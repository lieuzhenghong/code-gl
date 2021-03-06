#include <Parser.h>
#include <iostream>
#include <fstream>
#include <Instruction.h>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

const unsigned int NUM_REGISTERS = 16;

void Parser::handle_instruction(string* ins, vector<string>* r, vector<uint32_t>* out)
{
	if (*ins == "add")
	{
		// TODO
		// Syntax: add r2 r1 r0
		// Add r0 and r1 and save the result to r2
		out->push_back(Instruction::EncodeAdd(
			stoi((*r)[0]), 
			stoi((*r)[1]), 
			stoi((*r)[2])
			));
	}
	else if (*ins == "sub")
	{
		out->push_back(Instruction::EncodeSub(
			stoi((*r)[0]), 
			stoi((*r)[1]), 
			stoi((*r)[2])
			));
	}
	else if (*ins == "left")
	{
		out->push_back(Instruction::EncodeShl(
			stoi((*r)[0]), 
			stoi((*r)[1]), 
			stoi((*r)[2])
			));
	}
	else if (*ins == "right")
	{
		out->push_back(Instruction::EncodeShr(
			stoi((*r)[0]), 
			stoi((*r)[1]), 
			stoi((*r)[2])
			));
	}
	else if (*ins == "and")
	{
		out->push_back(Instruction::EncodeAnd(
			stoi((*r)[0]), 
			stoi((*r)[1]), 
			stoi((*r)[2])
			));
	}
	else if (*ins == "or")
	{
		out->push_back(Instruction::EncodeOr(
			stoi((*r)[0]), 
			stoi((*r)[1]), 
			stoi((*r)[2])
			));
	}
	else if (*ins == "xor")
	{
		out->push_back(Instruction::EncodeXor(
			stoi((*r)[0]), 
			stoi((*r)[1]), 
			stoi((*r)[2])
			));
	}
	else if (*ins == "mov")
	{
		// TODO
		// Syntax: mov r0 r1
		// Move the value of r[1] to r[0]
		out->push_back(Instruction::EncodeMov(stoi((*r)[0]), stoi((*r)[1])) );
	}
	else if (*ins == "load")
	{
		// Syntax: load r0 m0
		// Load the value of m[0] to r[0]
		out->push_back(Instruction::EncodeLoad(stoi((*r)[0]), stoi((*r)[1])) );
	}
	else if (*ins == "store")
	{
		// Syntax: store m0 r0
		// Store the value of r[0] into m[0]
		out->push_back(Instruction::EncodeStore(stoi((*r)[1]), stoi((*r)[0])) );
	}
	else if (*ins == "goto")
	{
		// TODO
		// Syntax: goto int 
		// Goto line number int -1 
		unsigned int addr = stoi((*r)[0]) - 1;
		out->push_back(Instruction::EncodeJmp( addr ));
	}
	else if (*ins == "set")
	{
		// TODO
		// Syntax: set r0 int
		// Set r0 to be an int

		// New syntax:
		// set all int
		// set all registers to be int

		if ((*r)[0] == "all")
		{
			for (unsigned int i = 0; i < NUM_REGISTERS; i++)
			{
				out->push_back(Instruction::EncodeMovI(i, stoi((*r)[1])));
			}
		}
		else{
			out->push_back(Instruction::EncodeMovI(stoi((*r)[0]), stoi((*r)[1])) );
		}
	}
	else if (*ins == "out")
	{
		// Syntax: out 
		for (unsigned int i = 0; i < NUM_REGISTERS; i++)
		{
			out->push_back(Instruction::EncodePScreen(i));
		}
		for (unsigned int i = 0; i < RAM_SIZE; i++)
		{
			out->push_back(Instruction::EncodePScreenRAM)
		}
	}
};

vector<uint32_t> Parser::Parse(string text)
{
	vector<string> r; // These are parameters of the commands
	bool reading_instruction = true;
	uint param_count = 0;
	string ins = "";
	string para = "";
	vector<uint32_t> out;

	r.clear();

	for (uint i = 0; text[i] != '\0'; i++)
	{
		//cout << "Character being read: " << text[i] << endl;
		if (reading_instruction)
		{
			// Since everything is space-delineated, I can toggle the flag once I hit a space
			if (text[i] == ' ')
			{
				//cout << "No longer reading instruction." << endl;
				reading_instruction = false;

				// Also, get ready to read a new parameter.
				r.push_back(string());
			}
			
			// Case where an instruction does not have parameters
			// We have hit a new line despite not having hit a space
			// (which would set reading_instruction to false, which
			// then allows us to cross over into the else loop)
			// So we must handle the behaviour whereby reading_instruction
			// is still true but we have hit a newline.
			else if (text[i] == '\n')
			{
				handle_instruction(&ins, &r, &out);
				ins = "";
				param_count = 0;
				r.clear();
				// This line is superfluous but whatever
				reading_instruction = true;
			}
			else
			{
				ins += text[i];
			}
		}
		else
		// We have a couple of cases when we are not reading an instruction
		// First, a special case: when we hit a new line
		// When we read a space, it could be two things:
		// We are about to read a parameter/ the next parameter;
		// Or the user is careless and has put whitespace at the end of the line.
		// But we're going to ignore that case right now.
		// Otherwise, we are reading parameters.
		// If we are reading a parameter:
		// Add each character to param until we hit a space.
		// Then, modify the output instruction.
		{
			// Start of a new line: we now start reading instruction again
			// This is assuming that one instruction fits on one line!!

			if (text[i] == '\n')
			{
				handle_instruction(&ins, &r, &out);
				ins = "";
				param_count=0;
				r.clear();
				reading_instruction = true;
			}
			else if (text[i] == ' ' || text[i] == '\t')
			// Get ready to read a new parameter
			{
				r.push_back(string());
				param_count++;
				//cout << "Reading new instruction..." << endl;
			}
			else
			{
				// We are now reading part of a parameter
				//cout << "Adding to parameter: " << text[i] << endl;
				r[param_count] += text[i];
				//cout << "Parameter " << param_count << " : " << r[param_count] << endl;
			}
		}
	}
	// We have reached the end of the file. Dump the final instructions
	//cout << "End of string. Parsing last instruction..." << endl;
	// Now handle the instruction
	handle_instruction(&ins, &r, &out);

	/*
	ofstream f;
	f.open("test");
	for (uint32_t i : out)
	{
		cout << d2b(i, 5) << endl;
		f << d2b(i,5) << " : " << i;
		f << '\n';
	}
	f.close();
	*/
	return out;
};

string Parser::d2b(uint32_t d, uint space)
{
	// Converts a decimal string 
	string temp = "";
	string output = "";
	uint counter = 0;
	uint blocks = 0;
    while (d) {
		//cout << d << endl;
		temp.insert(0, 1, (d%2 + '0'));
		//cout << temp << endl;
		d /= 2;
    }
	for (uint i = 0; i < 32; i++)
	{
			if (temp.length() > i)
			{
				output += temp[i];				
			}
			// Left-pad with 0s
			else
			{
				output.insert(0, 1, '0');
			}
	}
	for (uint j = 0; j < 32; j++)
	{
		if (counter >= space)
		{
			// We must insert +blocks because every time
			// we insert a space, the whole string moves one right
			// Otherwise, we wil lkeep inserting lefter and lefter
			output.insert(j+blocks, 1, ' ');
			counter = 0;
			blocks++;
		}
		counter++;
	}
	return output;
};

/*
List of commands
	void MovI(int reg, int imm);
	void Mov(int reg1, int reg2);
	void Add(int writeReg, int reg1, int reg2);
	void Sub(int writeReg, int reg1, int reg2);
	void Shl(int writeReg, int reg1, int reg2); // shift reg1 left by reg2
	void Shr(int writeReg, int reg1, int reg2);	// bitshift reg1 right by reg2
	void And(int writeReg, int reg1, int reg2);
	void Or(int writeReg, int reg1, int reg2);
	void Xor(int writeReg, int reg1, int reg2);
	void Load(int reg, int addrReg);
	void Store(int reg, int addrReg);
	void Jmp(int addr);
	void Jmpd(int addrReg);
	void Jal(int linkReg, int addr);
	void Jz(int condReg, int addr);
	void Jnz(int condReg, int addr);
	void Jn(int condReg, int addr);
	void Jnn(int condReg, int addr);
	void Print(int reg);
	void Halt();

*/
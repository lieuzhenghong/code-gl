#include <parser.h>
#include <iostream>
#include <fstream>
#include <Instruction.h>
#include <vector>

using namespace std;

int Parser::parse(string text)
{
	vector<string> r; // These are parameters of the commands
	bool reading_instruction = true;
	uint param_count = 0;
	string ins = "";
	string para = "";
	string out = "";

	r.clear();

	for (uint i = 0; text[i] != '\0'; i++)
	{
		if (reading_instruction)
		{
			// Since everything is space-delineated, I can toggle the flag once I hit a space
			if (text[i] = " ")
			{
				reading_instruction = false;	
			}
			ins += text[i];
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
				// Now handle the instruction
				switch (ins)
				{
					case (ins == "add")
					{
						// TODO
						// Syntax: add r0 r1 r2
						// Add r0 and r1 and save the result to r2
 						out += Instruction::EncodeAdd(r[02], r[1], r[0]);
						break;
					}
					case (ins == "mov")
					{
						// TODO
						// Syntax: mov r0 r1
						// Move the value of r[0] to r[1]
						out += Instruction::EncodeMov(r[1], r[0]);
						break;
					}
					case (ins == "set")
					{
						// TODO
						// Syntax: set r0 int
						// Set r0 to be an int
						out += Instruction::EncodeMovI(r[0], r[1]);
						break;
					}
				}
				reading_instruction = true;
				out += '\n';
			}
			else if (text[i] == ' ' || text[i] == '\t')
			// Get ready to read a new parameter
			{
				r.push_back(string());
				param_count++;
			}
			else
			{
				// We are now reading part of a parameter
				r[param_count] += text[i];
			}
		}
	}
	// output into a file to debug
	ofstream f;
	f.open("test.txt");
	f << out;
	f.close();
	return 0;
}


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

	void InvalidOpcode();

	void FlashMem(int addr, unsigned int val);
	void RunCycle();
	void Reset();

	Processor p = Processor();
	p.FlashMem(0, Instruction::EncodeMovI(0, 5));
	p.FlashMem(1, Instruction::EncodeMovI(1, 7));
	p.FlashMem(2, Instruction::EncodeMovI(2, 0));
	p.FlashMem(3, Instruction::EncodeMovI(3, 1));
	p.FlashMem(4, Instruction::EncodeJz(1, 8));
	p.FlashMem(5, Instruction::EncodeAdd(2, 2, 0));
	p.FlashMem(6, Instruction::EncodeSub(1, 1, 3));
	p.FlashMem(7, Instruction::EncodeJmp(3));
	p.FlashMem(8, Instruction::EncodePrint(2));
	p.FlashMem(9, Instruction::EncodeHalt());

	int cnt = 0;
	while(p.GetError() == Processor::ErrorCode::NO_ERROR){
		cnt++;
		p.RunCycle();
	}

	return 0;
*/

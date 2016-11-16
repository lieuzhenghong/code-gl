#pragma once

#include<Processor.h>

class Instruction{
	public:
	enum class Opcode{
		NOOP = 0, HALT,
		MOVI, MOV,
		ADD = 4, SUB, SHL, SHR,
		AND = 8, OR, XOR,
		LOAD = 12, STORE,
		PRINT,
		JMP = 16, JMPD, JAL,
		JZ = 20, JNZ, JN, JNN,
		INVALID
	};
	static const int OPCODE_MAP_SIZE = 32;
	static const Opcode OPCODE_MAP[OPCODE_MAP_SIZE];
	static const int OPCODE_OFFSET = 25;
	static const int OPCODE_WIDTH = 7;
	static const int LIMM_OFFSET = 0;
	static const int LIMM_WIDTH = 20;
	static const int WRITE_REG_OFFSET = 20;
	static const int WRITE_REG_WIDTH = 5;
	static const int REG1_OFFSET = 15;
	static const int REG1_WIDTH = 5;
	static const int REG2_OFFSET = 10;
	static const int REG2_WIDTH = 5;

	static void Execute(int instruction, Processor *processor);
	static unsigned int EncodeNoop();
	static unsigned int EncodeMovI(int reg, int imm);
	static unsigned int EncodeMov(int writeReg, int readReg);
	static unsigned int EncodeAdd(int writeReg, int reg1, int reg2);
	static unsigned int EncodeSub(int writeReg, int reg1, int reg2);
	static unsigned int EncodeShl(int writeReg, int reg1, int reg2);
	static unsigned int EncodeShr(int writeReg, int reg1, int reg2);
	static unsigned int EncodeAnd(int writeReg, int reg1, int reg2);
	static unsigned int EncodeOr(int writeReg, int reg1, int reg2);
	static unsigned int EncodeXor(int writeReg, int reg1, int reg2);
	static unsigned int EncodeLoad(int writeReg, int addrReg);
	static unsigned int EncodeStore(int readReg, int addrReg);
	static unsigned int EncodeJmp(int addr);
	static unsigned int EncodeJmpd(int addrReg);
	static unsigned int EncodeJal(int linkReg, int addr);
	static unsigned int EncodeJz(int condReg, int addr);
	static unsigned int EncodeJnz(int condReg, int addr);
	static unsigned int EncodeJn(int condReg, int addr);
	static unsigned int EncodeJnn(int condReg, int addr);
	static unsigned int EncodeHalt();
	static unsigned int EncodePrint(int reg);

	private:
	Instruction();

	static int getField(unsigned int instruction, int offset, int width);
	static unsigned int setField(int val, int offset, int width);

	static int getWriteRegField(int instruction);
	static int getReg1Field(int instruction);
	static int getReg2Field(int instruction);
	static int getLimmField(int instruction);
	static unsigned int encodeO(Opcode opcode);
	static unsigned int encodeOI(Opcode opcode, int imm);
	static unsigned int encodeOR(Opcode opcode, int reg);
	static unsigned int encodeORI(Opcode opcode, int reg, int imm);
	static unsigned int encodeORR(Opcode opcode, int writeReg, int reg1);
	static unsigned int encodeORRR(Opcode opcode, int writeReg, int reg1, int reg2);

	static void assertRegRange(int reg);
};

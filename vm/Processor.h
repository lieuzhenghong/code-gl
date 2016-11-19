#pragma once

#include<MemoryUnit.h>
#include<Screen.h>

class Processor{
	public:
	enum class ErrorCode {
		NO_ERROR = 0,
		HALTED,
		BAD_INSTRUCTION,
		INVALID_MEMORY_ACCESS,
		INVALID_OPCODE
	};

	static const int NUM_REGISTERS = 16;
	static const int RAM_SIZE = 1024;

	Processor();

	ErrorCode GetError();

	void MovI(int reg, int imm);
	void Mov(int reg1, int reg2);
	void Add(int writeReg, int reg1, int reg2);
	void Sub(int writeReg, int reg1, int reg2);
	void Shl(int writeReg, int reg1, int reg2);
	void Shr(int writeReg, int reg1, int reg2);
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

	// I/O functions
	void ConnectScreen(Screen* screen);
	void Screen(int reg);

	private:
	ErrorCode currError;
	unsigned int regs[NUM_REGISTERS];
	unsigned int pc;
	MemoryUnit ram;

	bool isRegisterInRange(int reg);
	bool assertRegisterInRange(int reg);

	void emitError(ErrorCode err);

	// I/O stuff
	Screen* screen = NULL;
};

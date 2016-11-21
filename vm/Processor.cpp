#include<iostream>
#include<Processor.h>
#include<Instruction.h>
#include<Screen.h>

using namespace std;

Processor::Processor():
	currError(ErrorCode::NO_ERROR),
	pc(0),
	ram(MemoryUnit(RAM_SIZE))
{
}

Processor::ErrorCode Processor::GetError(){
	return currError;
}


void Processor::MovI(int reg, int imm){
	if(!assertRegisterInRange(reg))
		return;
	regs[reg] = imm;
}

void Processor::Mov(int reg1, int reg2){
	if(!assertRegisterInRange(reg1) || !assertRegisterInRange(reg2))
		return;
	regs[reg1] = regs[reg2];
}

void Processor::Add(int writeReg, int reg1, int reg2){
	if(!assertRegisterInRange(writeReg) ||
		!assertRegisterInRange(reg1) ||
		!assertRegisterInRange(reg2))
		return;
	regs[writeReg] = (regs[reg1] + regs[reg2]) & ((uint32_t)(-1));
}

void Processor::Sub(int writeReg, int reg1, int reg2){
	if(!assertRegisterInRange(writeReg) ||
		!assertRegisterInRange(reg1) ||
		!assertRegisterInRange(reg2))
		return;
	regs[writeReg] = (regs[reg1] - regs[reg2]) & ((uint32_t)(-1));
}

void Processor::Shl(int writeReg, int reg1, int reg2){
	if(!assertRegisterInRange(writeReg) ||
		!assertRegisterInRange(reg1) ||
		!assertRegisterInRange(reg2))
		return;
	regs[writeReg] = (regs[reg1] << regs[reg2]) & ((uint32_t)(-1));
}

void Processor::Shr(int writeReg, int reg1, int reg2){
	if(!assertRegisterInRange(writeReg) ||
		!assertRegisterInRange(reg1) ||
		!assertRegisterInRange(reg2))
		return;
	regs[writeReg] = (regs[reg1] >> regs[reg2]) & ((uint32_t)(-1));
}

void Processor::And(int writeReg, int reg1, int reg2){
	if(!assertRegisterInRange(writeReg) ||
		!assertRegisterInRange(reg1) ||
		!assertRegisterInRange(reg2))
		return;
	regs[writeReg] = regs[reg1] & regs[reg2];
}

void Processor::Or(int writeReg, int reg1, int reg2){
	if(!assertRegisterInRange(writeReg) ||
		!assertRegisterInRange(reg1) ||
		!assertRegisterInRange(reg2))
		return;
	regs[writeReg] = regs[reg1] | regs[reg2];
}

void Processor::Xor(int writeReg, int reg1, int reg2){
	if(!assertRegisterInRange(writeReg) ||
		!assertRegisterInRange(reg1) ||
		!assertRegisterInRange(reg2))
		return;
	regs[writeReg] = regs[reg1] ^ regs[reg2];
}

void Processor::Load(int reg, int addrReg){
	if(!assertRegisterInRange(reg) ||
		!assertRegisterInRange(addrReg))
		return;
	if(!ram.Load(regs[addrReg], regs[reg]))
		emitError(ErrorCode::INVALID_MEMORY_ACCESS);
}

void Processor::Store(int reg, int addrReg){
	if(!assertRegisterInRange(reg) ||
		!assertRegisterInRange(addrReg))
		return;
	if(!ram.Store(regs[addrReg], regs[reg]))
		emitError(ErrorCode::INVALID_MEMORY_ACCESS);
}

void Processor::Jmp(int addr){
	pc = addr;
}

void Processor::Jmpd(int addrReg){
	if(!assertRegisterInRange(addrReg))
		return;
	pc = regs[addrReg];
}

void Processor::Jal(int linkReg, int addr){
	if(!assertRegisterInRange(linkReg))
		return;
	regs[linkReg] = pc;
	pc = addr;
}

void Processor::Jz(int condReg, int addr){
	if(!assertRegisterInRange(condReg))
		return;
	if(regs[condReg] == 0)
		pc = addr;
}

void Processor::Jnz(int condReg, int addr){
	if(!assertRegisterInRange(condReg))
		return;
	if(regs[condReg] != 0)
		pc = addr;
}

void Processor::Jn(int condReg, int addr){
	if(!assertRegisterInRange(condReg))
		return;
	if(regs[condReg] < (((unsigned int)1) << 31))
		pc = addr;
}

void Processor::Jnn(int condReg, int addr){
	if(!assertRegisterInRange(condReg))
		return;
	if(regs[condReg] >= (((unsigned int)1) << 31))
		pc = addr;
}

void Processor::Halt(){
	currError = ErrorCode::HALTED;
}

void Processor::Print(int reg){
	if(!assertRegisterInRange(reg))
		return;
	cout << "Output: " << regs[reg] << endl;
}

void Processor::InvalidOpcode(){
	emitError(ErrorCode::INVALID_OPCODE);
}

void Processor::FlashMem(int addr, unsigned int val){
	ram.Store(addr, val);
}

void Processor::RunCycle(){
	unsigned int instruction;
	if(!ram.Load(pc, instruction)){
		emitError(ErrorCode::INVALID_MEMORY_ACCESS);
		return;
	}
	pc = (pc + 1) & ((uint32_t)(-1));
	Instruction::Execute(instruction, this);
}

void Processor::Reset(){
	pc = 0;
	currError = ErrorCode::NO_ERROR;
}

bool Processor::isRegisterInRange(int reg){
	return reg >= 0 && reg < NUM_REGISTERS;
}

bool Processor::assertRegisterInRange(int reg){
	if(!isRegisterInRange(reg)){
		emitError(ErrorCode::BAD_INSTRUCTION);
		return false;
	}
	return true;
}

void Processor::emitError(ErrorCode err){
	currError = err;
	cout << "Processor encountered error code " << static_cast<int>(err) << " at position " << pc << endl;
}

// I/O functions

void Processor::ConnectScreen(Screen* the_screen){
	screen = the_screen;
}

void Processor::PScreen(int reg){
	if(!assertRegisterInRange(reg))
		return;
	screen->ReadWord(regs[reg]);
}
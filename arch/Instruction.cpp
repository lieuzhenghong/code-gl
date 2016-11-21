#include<iostream>
#include<cassert>
#include<Instruction.h>
#include<Processor.h>

using namespace std;

const Instruction::Opcode Instruction::OPCODE_MAP[OPCODE_MAP_SIZE] = {
	Opcode::NOOP, Opcode::HALT, Opcode::MOVI, Opcode::MOV,
	Opcode::ADD, Opcode::SUB, Opcode::SHL, Opcode::SHR,
	Opcode::AND, Opcode::OR, Opcode::XOR, Opcode::INVALID,
	Opcode::LOAD, Opcode::STORE, Opcode::PRINT, Opcode::PSCREEN,

	Opcode::JMP, Opcode::JMPD, Opcode::JAL, Opcode::INVALID,
	Opcode::JZ, Opcode::JNZ, Opcode::JN, Opcode::JNN,
	Opcode::INVALID, Opcode::INVALID, Opcode::INVALID, Opcode::INVALID,
	Opcode::INVALID, Opcode::INVALID, Opcode::INVALID, Opcode::INVALID
};

void Instruction::Execute(int instruction, Processor *processor){
	int opcodeVal = getField(instruction, OPCODE_OFFSET, OPCODE_WIDTH);
	if(opcodeVal < 0 || opcodeVal >= OPCODE_MAP_SIZE){
		processor->InvalidOpcode();
		return;
	}
	Opcode opcode = Instruction::OPCODE_MAP[opcodeVal];
	switch(opcode){
	case Opcode::NOOP:
		break;
	case Opcode::INVALID:
		processor->InvalidOpcode();
		break;
	case Opcode::HALT:
		processor->Halt();
		break;
	case Opcode::MOVI:
		processor->MovI(
			getWriteRegField(instruction),
			getLimmField(instruction)
		);
		break;
	case Opcode::MOV:
		processor->Mov(
			getWriteRegField(instruction),
			getReg1Field(instruction)
		);
		break;
	case Opcode::ADD:
		processor->Add(
			getWriteRegField(instruction),
			getReg1Field(instruction),
			getReg2Field(instruction)
		);
		break;
	case Opcode::SUB:
		processor->Sub(
			getWriteRegField(instruction),
			getReg1Field(instruction),
			getReg2Field(instruction)
		);
		break;
	case Opcode::SHL:
		processor->Shl(
			getWriteRegField(instruction),
			getReg1Field(instruction),
			getReg2Field(instruction)
		);
		break;
	case Opcode::SHR:
		processor->Shr(
			getWriteRegField(instruction),
			getReg1Field(instruction),
			getReg2Field(instruction)
		);
		break;
	case Opcode::AND:
		processor->And(
			getWriteRegField(instruction),
			getReg1Field(instruction),
			getReg2Field(instruction)
		);
		break;
	case Opcode::OR:
		processor->Or(
			getWriteRegField(instruction),
			getReg1Field(instruction),
			getReg2Field(instruction)
		);
		break;
	case Opcode::XOR:
		processor->Xor(
			getWriteRegField(instruction),
			getReg1Field(instruction),
			getReg2Field(instruction)
		);
		break;
	case Opcode::LOAD:
		processor->Load(
			getWriteRegField(instruction),
			getReg1Field(instruction)
		);
		break;
	case Opcode::STORE:
		processor->Store(
			getWriteRegField(instruction),
			getReg1Field(instruction)
		);
		break;
	case Opcode::JMP:
		processor->Jmp(
			getLimmField(instruction)
		);
		break;
	case Opcode::JMPD:
		processor->Jmpd(
			getWriteRegField(instruction)
		);
		break;
	case Opcode::JAL:
		processor->Jal(
			getWriteRegField(instruction),
			getLimmField(instruction)
		);
		break;
	case Opcode::JZ:
		processor->Jz(
			getWriteRegField(instruction),
			getLimmField(instruction)
		);
		break;
	case Opcode::JNZ:
		processor->Jnz(
			getWriteRegField(instruction),
			getLimmField(instruction)
		);
		break;
	case Opcode::JN:
		processor->Jn(
			getWriteRegField(instruction),
			getLimmField(instruction)
		);
		break;
	case Opcode::JNN:
		processor->Jnn(
			getWriteRegField(instruction),
			getLimmField(instruction)
		);
		break;
	case Opcode::PRINT:
		processor->Print(
			getWriteRegField(instruction)
		);
		break;
	case Opcode::PSCREEN:
		processor->PScreen(
			getWriteRegField(instruction)
		);
		break;
	default:
		assert(false); // Opcode not implemented
		break;
	}
}

unsigned int Instruction::EncodeNoop(){
	return encodeO(Opcode::NOOP);
}

unsigned int Instruction::EncodeMovI(int reg, int imm){
	return encodeORI(Opcode::MOVI, reg, imm);
}

unsigned int Instruction::EncodeMov(int writeReg, int readReg){
	return encodeORR(Opcode::MOV, writeReg, readReg);
}

unsigned int Instruction::EncodeAdd(int writeReg, int reg1, int reg2){
	return encodeORRR(Opcode::ADD, writeReg, reg1, reg2);
}

unsigned int Instruction::EncodeSub(int writeReg, int reg1, int reg2){
	return encodeORRR(Opcode::SUB, writeReg, reg1, reg2);
}

unsigned int Instruction::EncodeShl(int writeReg, int reg1, int reg2){
	return encodeORRR(Opcode::SHL, writeReg, reg1, reg2);
}

unsigned int Instruction::EncodeShr(int writeReg, int reg1, int reg2){
	return encodeORRR(Opcode::SHR, writeReg, reg1, reg2);
}

unsigned int Instruction::EncodeAnd(int writeReg, int reg1, int reg2){
	return encodeORRR(Opcode::AND, writeReg, reg1, reg2);
}

unsigned int Instruction::EncodeOr(int writeReg, int reg1, int reg2){
	return encodeORRR(Opcode::OR, writeReg, reg1, reg2);
}

unsigned int Instruction::EncodeXor(int writeReg, int reg1, int reg2){
	return encodeORRR(Opcode::XOR, writeReg, reg1, reg2);
}
unsigned int Instruction::EncodeLoad(int writeReg, int addrReg){
	return encodeORR(Opcode::LOAD, writeReg, addrReg);
}

unsigned int Instruction::EncodeStore(int readReg, int addrReg){
	return encodeORR(Opcode::STORE, readReg, addrReg);
}

unsigned int Instruction::EncodeJmp(int addr){
	return encodeOI(Opcode::JMP, addr);
}

unsigned int Instruction::EncodeJmpd(int addrReg){
	return encodeOR(Opcode::JMPD, addrReg);
}

unsigned int Instruction::EncodeJal(int linkReg, int addr){
	return encodeORI(Opcode::JAL, linkReg, addr);
}

unsigned int Instruction::EncodeJz(int condReg, int addr){
	return encodeORI(Opcode::JZ, condReg, addr);
}

unsigned int Instruction::EncodeJnz(int condReg, int addr){
	return encodeORI(Opcode::JNZ, condReg, addr);
}

unsigned int Instruction::EncodeJn(int condReg, int addr){
	return encodeORI(Opcode::JN, condReg, addr);
}

unsigned int Instruction::EncodeJnn(int condReg, int addr){
	return encodeORI(Opcode::JNN, condReg, addr);
}

unsigned int Instruction::EncodeHalt(){
	return encodeO(Opcode::HALT);
}

unsigned int Instruction::EncodePrint(int reg){
	return encodeOR(Opcode::PRINT, reg);
}

unsigned int Instruction::EncodePScreen(int reg){
	return encodeOR(Opcode::PSCREEN, reg);
}

int Instruction::getField(unsigned int instruction, int offset, int width){
	return (instruction >> offset) & ((1 << width) - 1);
}

unsigned int Instruction::setField(int val, int offset, int width){
	return (val & ((1  << width) - 1)) << offset;
}

int Instruction::getWriteRegField(int instruction){
	return getField(instruction, WRITE_REG_OFFSET, WRITE_REG_WIDTH);
}

int Instruction::getReg1Field(int instruction){
	return getField(instruction, REG1_OFFSET, REG1_WIDTH);
}

int Instruction::getReg2Field(int instruction){
	return getField(instruction, REG2_OFFSET, REG2_WIDTH);
}

int Instruction::getLimmField(int instruction){
	return getField(instruction, LIMM_OFFSET, LIMM_WIDTH);
}

unsigned int Instruction::encodeO(Opcode opcode){
	return setField(static_cast<int>(opcode), OPCODE_OFFSET, OPCODE_WIDTH);
}

unsigned int Instruction::encodeOI(Opcode opcode, int imm){
	return setField(static_cast<int>(opcode), OPCODE_OFFSET, OPCODE_WIDTH) |
		setField(imm, LIMM_OFFSET, LIMM_WIDTH);
}

unsigned int Instruction::encodeOR(Opcode opcode, int reg){
	assertRegRange(reg);
	return setField(static_cast<int>(opcode), OPCODE_OFFSET, OPCODE_WIDTH) |
		setField(reg, WRITE_REG_OFFSET, WRITE_REG_WIDTH);
}

unsigned int Instruction::encodeORI(Opcode opcode, int reg, int imm){
	assertRegRange(reg);
	return setField(static_cast<int>(opcode), OPCODE_OFFSET, OPCODE_WIDTH) |
		setField(reg, WRITE_REG_OFFSET, WRITE_REG_WIDTH) |
		setField(imm, LIMM_OFFSET, LIMM_WIDTH);
}

unsigned int Instruction::encodeORR(Opcode opcode, int writeReg, int reg1){
	assertRegRange(writeReg);
	assertRegRange(reg1);
	return setField(static_cast<int>(opcode), OPCODE_OFFSET, OPCODE_WIDTH) |
		setField(writeReg, WRITE_REG_OFFSET, WRITE_REG_WIDTH) |
		setField(reg1, REG1_OFFSET, REG1_WIDTH);
}

unsigned int Instruction::encodeORRR(Opcode opcode, int writeReg, int reg1, int reg2){
	assertRegRange(writeReg);
	assertRegRange(reg1);
	assertRegRange(reg2);
	return setField(static_cast<int>(opcode), OPCODE_OFFSET, OPCODE_WIDTH) |
		setField(writeReg, WRITE_REG_OFFSET, WRITE_REG_WIDTH) |
		setField(reg1, REG1_OFFSET, REG1_WIDTH) |
		setField(reg2, REG2_OFFSET, REG2_WIDTH);
}

void Instruction::assertRegRange(int reg){
	assert(reg >= 0 && reg < Processor::NUM_REGISTERS);
}

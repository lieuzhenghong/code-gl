#include<MemoryUnit.h>

using namespace std;

MemoryUnit::MemoryUnit(unsigned int size):
	size(size),
	mem(new unsigned int[size])
{
}

MemoryUnit::~MemoryUnit(){
	delete[] mem;
}

bool MemoryUnit::Load(unsigned int addr, unsigned int &val){
	if(!isAddrInRange(addr))
		return false;
	val = mem[addr];
	return true;
}

bool MemoryUnit::Store(unsigned int addr, unsigned int val){
	if(!isAddrInRange(addr))
		return false;
	mem[addr] = val;
	return true;
}


bool MemoryUnit::isAddrInRange(unsigned int addr){
	return addr >= 0 && addr < size;
}

#pragma once

class MemoryUnit{
	public:
	MemoryUnit(unsigned int size);
	~MemoryUnit();
	bool Load(unsigned int addr, unsigned int &val);
	bool Store(unsigned int addr, unsigned int val);

	private:
	unsigned int size;
	unsigned int *mem;

	bool isAddrInRange(unsigned int addr);
};

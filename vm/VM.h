class VM{
	public:
	void Mov(int reg1, int reg2);
	private:
	int regs[16];
	int ram[1024];
};

#pragma once
#include <string>
#include <vector>

using namespace std;

class Parser
{
    public:
        int parse(string text);
        string d2b(uint32_t d, uint space);

    private:
        void handle_instruction(string* ins, vector<string>* params, vector<uint32_t>* out);
};
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0027fa00 @ 0x0027fa00
struct State_27fa00 {
    unsigned int words[40];
    State_27fa00* FUN_0027fa00(const State_27fa00* source);
};

State_27fa00* State_27fa00::FUN_0027fa00(const State_27fa00* source)
{
    for (int i = 0; i < 40; ++i)
        words[i] = source->words[i];
    return this;
}

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0027fa00 @ 0x0027fa00
struct State {
    unsigned int words[40];
    State* FUN_0027fa00(const State* source);
};

State* State::FUN_0027fa00(const State* source)
{
    for (int i = 0; i < 40; ++i)
        words[i] = source->words[i];
    return this;
}

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d49c0 @ 0x002d49c0
struct Random { unsigned int first; unsigned int second; int FUN_002d49c0(int base, int range); };
int Random::FUN_002d49c0(int base, int range) {
    first = (first & 0xffffu) * 0x9069u + (first >> 16);
    second = (second & 0xffffu) * 0x4650u + (second >> 16);
    unsigned int value = (second & 0xffffu) + (first << 16);
    unsigned int divisor = (unsigned int)range * 2u + 1u;
    return (int)(value % divisor - (unsigned int)range + (unsigned int)base);
}
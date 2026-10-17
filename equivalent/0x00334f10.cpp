// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00334f10 @ 0x00334f10
struct State {
    char unused0[0x3c];
    unsigned int value3c;
    char unused1[0x48-0x40];
    unsigned int value48;
    char unused2[0x50-0x4c];
    unsigned int value50;
    char unused3[0x64-0x54];
    unsigned int value64;
    unsigned int value68;
    unsigned int value6c;
    unsigned int value70;
    unsigned int value74;
    char unused4[0x80-0x78];
    unsigned char value80;
    char unused5[3];
    unsigned int value84;
};
extern "C" unsigned int __cdecl FUN_0026fd80(unsigned int, unsigned int);
void __stdcall FUN_00334f10(State* state, unsigned int base, unsigned int source, unsigned int value, unsigned int unused) {
    unsigned int result = FUN_0026fd80(source, 0x4000);
    state->value64 = base;
    state->value6c = base;
    state->value70 = base;
    state->value68 = base + result;
    state->value84 = 0;
    state->value74 = result;
    state->value50 = value;
    state->value80 = 0;
    state->value3c = result;
    state->value48 = 0;
}
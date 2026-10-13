// STATUS: equivalent (tools/equiv.py level 3: 247 inputs, branch coverage 18/18)
// FUN_0033d7a0 @ 0x0033d7a0
struct State;
extern "C" int __cdecl FUN_00339fe0(State*, int, int);
extern "C" void __cdecl FUN_00339dc0(State*, int);
extern "C" int __cdecl FUN_00212f70(State*, int);
extern "C" double __cdecl FUN_002130e0(State*, int);
extern "C" void __cdecl FUN_00213340(State*, float);
extern "C" const char* __cdecl FUN_00339df0(State*, int, int);
extern "C" void __cdecl FUN_00339c30(State*, int, const char*);
extern "C" unsigned int __cdecl FUN_00345d81(const char*, char**, int);
extern "C" int __cdecl _isspace(int);
extern "C" void __cdecl FUN_00213320(State*);
int __cdecl FUN_0033d7a0(State* state) {
    int base = FUN_00339fe0(state, 2, 10);
    if (base == 10) {
        FUN_00339dc0(state, 1);
        if (FUN_00212f70(state, 1)) {
            float value = (float)FUN_002130e0(state, 1);
            FUN_00213340(state, value);
            return 1;
        }
    } else {
        const char* text = FUN_00339df0(state, 1, 0);
        if (base < 2 || base > 36)
            FUN_00339c30(state, 2, "base out of range");
        char* end;
        unsigned int value = FUN_00345d81(text, &end, base);
        if (end != text) {
            while (_isspace((unsigned char)*end)) ++end;
            if (*end == 0) {
                FUN_00213340(state, (float)value);
                return 1;
            }
        }
    }
    FUN_00213320(state);
    return 1;
}

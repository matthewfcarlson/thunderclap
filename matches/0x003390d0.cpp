struct State;
typedef int(__cdecl* Callback_3390d0)(State*);
struct Registration_3390d0 {
    const char* name;
    Callback_3390d0 function;
};
extern "C" {
void __cdecl FUN_002135a0(State*, int, const char*);
int __cdecl FUN_00212f00(State*, int);
void __cdecl FUN_00212d80(State*, int);
void __cdecl FUN_00213680(State*, int, int);
void __cdecl FUN_00212ed0(State*, int);
void __cdecl FUN_00213790(State*, int, const char*);
void __cdecl FUN_00212e20(State*, int);
void __cdecl FUN_002134a0(State*, Callback_3390d0, int);
}
void __cdecl FUN_003390d0(State* state, const char* name, const Registration_3390d0* entries, int upvalueCount) {
    if (name) {
        FUN_002135a0(state, -10001, name);
        if (!FUN_00212f00(state, -1)) {
            FUN_00212d80(state, -2);
            FUN_00213680(state, 0, 0);
            FUN_00212ed0(state, -1);
            FUN_00213790(state, -10001, name);
        }
        FUN_00212e20(state, -1 - upvalueCount);
    }
    if (entries->name) {
        int destination = -2 - upvalueCount;
        do {
            for (int i = 0; i < upvalueCount; ++i)
                FUN_00212ed0(state, -upvalueCount);
            FUN_002134a0(state, entries->function, upvalueCount);
            FUN_00213790(state, destination, entries->name);
            ++entries;
        } while (entries->name);
    }
    FUN_00212d80(state, -1 - upvalueCount);
}

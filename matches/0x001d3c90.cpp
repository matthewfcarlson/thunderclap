struct State;
typedef int(__cdecl* Callback)(State*);
extern int __cdecl FUN_001d0990(State*);
extern int __cdecl FUN_001d2000(State*);
extern int __cdecl FUN_001d2020(State*);
extern void __cdecl FUN_002151e0(State*);
extern State* __cdecl FUN_002150e0(Callback, int);
extern void __cdecl FUN_0033eb30(State*);
extern void __cdecl FUN_00212d80(State*, int);
extern void __cdecl FUN_0033d6c0(State*);
extern void __cdecl FUN_0033bca0(State*);
extern void __cdecl FUN_0033b560(State*);
extern void __cdecl FUN_0033ac90(State*);
extern void __cdecl FUN_00212ed0(State*, int);
extern void __cdecl FUN_003390d0(State*, int, const char*, int);
extern void __cdecl FUN_001d07b0(State*);
extern void __cdecl FUN_002134a0(State*, Callback, int);
extern void __cdecl FUN_00213790(State*, int, const char*);
struct Object {
    int FUN_001d1740(State*);
    int target(State**);
};
int Object::target(State** state) {
    if (*state) {
        FUN_002151e0(*state);
        *state = 0;
    }
    *state = FUN_002150e0(FUN_001d0990, 0);
    FUN_0033eb30(*state);
    FUN_00212d80(*state, 0);
    FUN_0033d6c0(*state);
    FUN_00212d80(*state, 0);
    FUN_0033bca0(*state);
    FUN_00212d80(*state, 0);
    FUN_0033b560(*state);
    FUN_00212d80(*state, 0);
    FUN_0033ac90(*state);
    FUN_00212d80(*state, 0);
    FUN_00212ed0(*state, -10001);
    FUN_003390d0(*state, 0, "h$B", 0);
    FUN_00212d80(*state, -2);
    FUN_001d07b0(*state);
    State* saved = *state;
    FUN_002134a0(saved, FUN_001d2000, 0);
    FUN_00213790(saved, -10001, "debug");
    FUN_002134a0(saved, FUN_001d2020, 0);
    FUN_00213790(saved, -10001, "cdebug");
    return FUN_001d1740(*state);
}

struct Obj {
    char pad[0x28];
    int value;
};
struct State {
    char pad[0x28];
    Obj* obj;
    int pad2;
    int count;
};
extern State* gState;
extern int __stdcall FUN_0020d7ff(Obj*, int, int);
extern void __stdcall FUN_0020c79c(Obj*, int, int);
void __cdecl FUN_00240c60(int param_1) {
    if (param_1) {
        int n = FUN_0020d7ff(gState->obj, 0, param_1);
        gState->count -= n;
        FUN_0020c79c(gState->obj, 0, param_1);
    }
}

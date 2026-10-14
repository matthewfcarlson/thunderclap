// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0033e3f0 @ 0x0033e3f0
struct State;
extern "C" {
void __cdecl FUN_00212d80(State*, int);
void __cdecl FUN_00213d30(State*, int);
int __cdecl FUN_00213160(State*, int);
int __cdecl FUN_00212f00(State*, int);
void __cdecl FUN_00213680(State*, int, int);
void __cdecl FUN_00212ed0(State*, int);
void __cdecl FUN_00213520(State*, int);
void __cdecl FUN_00213800(State*, int);
void __cdecl FUN_002138e0(State*, int);
int __cdecl FUN_002136d0(State*, int);
void __cdecl FUN_00213600(State*, int);
void __cdecl FUN_00339c30(State*, int, const char*);
}
int __cdecl FUN_0033e3f0(State* state)
{
    FUN_00212d80(state, 1);
    FUN_00213d30(state, 0);
    if (FUN_00213160(state, 1)) {
        if (FUN_00212f00(state, 1) == 1) {
            FUN_00213680(state, 0, 0);
            FUN_00212ed0(state, -1);
            FUN_00213520(state, 1);
            FUN_00213800(state, -10002);
            FUN_002138e0(state, 2);
            return 1;
        }
        int valid = 0;
        if (FUN_002136d0(state, 1)) {
            FUN_00213600(state, -10002);
            valid = FUN_00213160(state, -1);
            FUN_00212d80(state, -2);
        }
        if (!valid)
            FUN_00339c30(state, 1, "boolean or proxy expected");
        FUN_002136d0(state, 1);
        FUN_002138e0(state, 2);
    }
    return 1;
}

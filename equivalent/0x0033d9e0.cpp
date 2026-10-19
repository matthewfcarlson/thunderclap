// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 8/8)
// FUN_0033d9e0 @ 0x0033d9e0
// cl-flags: /GS
struct LuaState;
struct DebugInfo_33d9e0 { char data[96]; };
extern int __cdecl FUN_00212f00(LuaState*, int);
extern void __cdecl FUN_00212ed0(LuaState*, int);
extern int __cdecl FUN_00339fe0(LuaState*, int, int);
extern void __cdecl FUN_00339c30(LuaState*, int, const char*);
extern int __cdecl FUN_00213fc0(LuaState*, int, DebugInfo_33d9e0*);
extern void __cdecl FUN_00214bd0(LuaState*, const char*, DebugInfo_33d9e0*);
extern void __cdecl FUN_00338e20(LuaState*, const char*, int);
// equiv-conv: FUN_0033d9e0 esi
void __cdecl FUN_0033d9e0(LuaState* state) {
    DebugInfo_33d9e0 info;
    if (FUN_00212f00(state, 1) == 6) {
        FUN_00212ed0(state, 1);
    } else {
        int level = FUN_00339fe0(state, 1, 1);
        if (level < 0)
            FUN_00339c30(state, 1, "level must be non-negative");
        if (!FUN_00213fc0(state, level, &info))
            FUN_00339c30(state, 1, "invalid level");
        FUN_00214bd0(state, "f", &info);
        if (!FUN_00212f00(state, -1))
            FUN_00338e20(state, "no function environment for tail call at level %d", level);
    }
}

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0033b6d0 @ 0x0033b6d0
// Lua math.asin: lua_pushnumber(L, asin(luaL_checknumber(L, 1))); return 1.
// FUN_003442bc is the CRT's __CIasin (x87 argument and result: fld1/fadd/fsub/fmul/fsqrt/fpatan).
extern "C" double asin(double);
float __cdecl FUN_00339ec0(int L, int narg);
void __cdecl FUN_00213340(int L, float n);

// equiv-map: __CIasin = 0x003442bc
int __cdecl FUN_0033b6d0(int L)
{
    FUN_00213340(L, (float)asin(FUN_00339ec0(L, 1)));
    return 1;
}

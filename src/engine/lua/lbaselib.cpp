// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0033d6e0..0x0033eb70 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_fc191ef1 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc191ef1 {} using namespace fn_fc191ef1;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_fc191ef1 {
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_002139a0(LuaVMState* L, int nargs, int nresults);
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00347eed(const void*, const void*);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern float hulk_at_004d9a10;
extern "C" int __cdecl FUN_00339fe0(LuaVMState* L, int narg, int def);
extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00212f70(LuaVMState* L, int idx);
extern "C" float __cdecl FUN_002130e0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" unsigned int __cdecl FUN_00345d81(const char*, char**, int);
extern "C" void __cdecl FUN_00213320(LuaVMState* L);
extern "C" int __cdecl FUN_00212fb0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00338d90(LuaVMState* L, int level);
extern "C" void __cdecl FUN_00213c90(LuaVMState* L, int n);
extern "C" int __cdecl FUN_00213c40(LuaVMState* L);
extern "C" int __cdecl FUN_002136d0(LuaVMState* L, int objindex);
extern "C" int __cdecl FUN_00339010(LuaVMState* L, int obj, const char* event);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
extern "C" int __cdecl FUN_002138e0(LuaVMState* L, int objindex);
void __cdecl FUN_0033d9e0(LuaVMState* L);
extern "C" void __cdecl FUN_00213720(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" void __cdecl FUN_00213600(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212e60(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00213950(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00213010(LuaVMState* L, int index1, int index2);
extern "C" void __cdecl FUN_00213520(LuaVMState* L, int b);
extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00213ba0(LuaVMState* L, int what, int data);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);
extern "C" int __cdecl FUN_00213120(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" const char* __cdecl FUN_00339e60(LuaVMState* L, int narg, const char* def, unsigned int* len);
extern "C" int __cdecl FUN_00338e50(const char* name, const char* const* list);
extern "C" const char* __cdecl FUN_00212f20(LuaVMState* L, int t);
extern "C" int __cdecl FUN_00213c50(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213640(LuaVMState* L, int idx, int n);
extern "C" int __cdecl FUN_00339a60(LuaVMState* L, const char* buff, unsigned int size, const char* name);
extern "C" void __cdecl FUN_00212e20(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00339800(LuaVMState* L, const char* filename);
extern "C" void __cdecl FUN_00339710(LuaVMState* L, int t, int ref);
extern "C" unsigned int __cdecl FUN_002131f0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00339650(LuaVMState* L, int t);
extern "C" const char* __cdecl FUN_0033df70(LuaVMState* L, void* ud, unsigned int* size);
extern "C" int __cdecl FUN_00213b20(LuaVMState* L, LuaVMReader reader, void* data, const char* chunkname);
extern "C" int __cdecl FUN_00213160(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_003392c0(LuaVMState* L, int t);
extern "C" void __cdecl FUN_00338fe0(LuaVMState* L, int space, const char* mes);
extern "C" int __cdecl FUN_002139f0(LuaVMState* L, int nargs, int nresults, int errfunc);
extern "C" {
void* __cdecl FUN_00213d30(LuaVMState* L, unsigned int size);
}
extern "C" {
void __cdecl FUN_00213680(LuaVMState* L, int narray, int nrec);
}
extern "C" {
void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
}
void FUN_0033e570(LuaVMState* L);
const char* FUN_0033e4d0(LuaVMState* L);
extern "C" int __cdecl FUN_00212c50(LuaVMState* L, int size);
extern "C" void __cdecl FUN_00212cb0(LuaVMState* from, LuaVMState* to, int n);
extern "C" int __cdecl FUN_00215d10(LuaVMState* L, int nargs);
extern "C" LuaVMState *__cdecl FUN_00213290(LuaVMState *L, int idx);
int FUN_0033e7f0(int narg, LuaVMState *co, LuaVMState *L);
extern "C" LuaVMState* __cdecl FUN_00212d30(LuaVMState* L);
extern "C" int __cdecl FUN_00212f40(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_0033e8f0(LuaVMState* L);
extern "C" int __cdecl FUN_0033e950(LuaVMState* L);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" int __cdecl FUN_00215b60(LuaVMState* L, int nresults);
extern "C" void __cdecl FUN_003390d0(LuaVMState *L, const char *libname, const LuaVMReg *l, int nup);
extern "C" int __cdecl FUN_0033e3f0(LuaVMState *L);
void FUN_0033ea90(LuaVMState* L);


// 0x0033d6e0 FUN_0033d6e0 (184 B): matches/0x0033d6e0.cpp
// sym: _FUN_0033d6e0
// luaB_print
// data: error = DAT_0042251c, tostring = DAT_00422548; zero_33d6e0 is the CRT's stdout (0x004d9a10)
extern "C" int __cdecl FUN_0033d6e0(LuaVMState* L) {
    int n = FUN_00212d70(L);
    FUN_002135a0(L, -10001, DAT_00422548);
    for (int i = 1; i <= n; ++i) {
        FUN_00212ed0(L, -1);
        FUN_00212ed0(L, i);
        FUN_002139a0(L, 1, 1);
        const char* s = FUN_00213190(L, -1);
        if (!s)
            return FUN_00338e20(L, DAT_0042251c);
        if (i > 1)
            FUN_00347eed(DAT_00434f70, &hulk_at_004d9a10);
        FUN_00347eed(s, &hulk_at_004d9a10);
        FUN_00212d80(L, -2);
    }
    FUN_00347eed(DAT_00422518, &hulk_at_004d9a10);
    return 0;
}


// 0x0033d7a0 FUN_0033d7a0 (272 B): equivalent/0x0033d7a0.cpp
// sym: _FUN_0033d7a0 @04e75786d091 @w8eaedb304b63
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 18/18)
// FUN_0033d7a0 @ 0x0033d7a0
// luaB_tonumber
extern "C" int __cdecl FUN_0033d7a0(LuaVMState* L) {
    int base = FUN_00339fe0(L, 2, 10);
    if (base == 10) {
        FUN_00339dc0(L, 1);
        if (FUN_00212f70(L, 1)) {
            FUN_00213340(L, FUN_002130e0(L, 1));
            return 1;
        }
    } else {
        const char* s1 = FUN_00339df0(L, 1, 0);
        if (base < 2 || base > 36)
            FUN_00339c30(L, 2, "base out of range");
        char* s2;
        unsigned int n = FUN_00345d81(s1, &s2, base);
        if (s2 != s1) {
            while (_isspace((unsigned char)*s2)) ++s2;
            if (*s2 == 0) {
                FUN_00213340(L, (float)n);
                return 1;
            }
        }
    }
    FUN_00213320(L);
    return 1;
}


// 0x0033d8b0 FUN_0033d8b0 (83 B): matches/0x0033d8b0.cpp
// sym: _FUN_0033d8b0
// luaB_error
extern "C" int __cdecl FUN_0033d8b0(LuaVMState* L) {
    int level = FUN_00339fe0(L, 2, 1);
    FUN_00212d80(L, 1);
    if (FUN_00212fb0(L, 1) && level > 0) {
        FUN_00338d90(L, level);
        FUN_00212ed0(L, 1);
        FUN_00213c90(L, 2);
    }
    return FUN_00213c40(L);
}


// 0x0033d910 FUN_0033d910 (67 B): matches/0x0033d910.cpp
// sym: _FUN_0033d910
// luaB_getmetatable
extern "C" int __cdecl FUN_0033d910(LuaVMState* L) {
    FUN_00339dc0(L, 1);
    if (FUN_002136d0(L, 1) == 0) {
        FUN_00213320(L);
        return 1;
    }
    FUN_00339010(L, 1, "__metatable");
    return 1;
}


// 0x0033d960 FUN_0033d960 (115 B): matches/0x0033d960.cpp
// sym: _FUN_0033d960
// luaB_setmetatable
extern "C" int __cdecl FUN_0033d960(LuaVMState* L) {
    int t = FUN_00212f00(L, 2);
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    if (t != LUAVM_TNIL && t != LUAVM_TTABLE)
        FUN_00339c30(L, 2, "nil or table expected");
    if (FUN_00339010(L, 1, "__metatable"))
        FUN_00338e20(L, "cannot change a protected metatable");
    FUN_00212d80(L, 2);
    FUN_002138e0(L, 1);
    return 1;
}


// 0x0033dad0 FUN_0033dad0 (72 B): equivalent/0x0033dad0.cpp
// sym: _FUN_0033dad0 @0b967e71ab51 @w08606197e7d8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033dad0 @ 0x0033dad0
// luaB_getfenv
// equiv-conv: FUN_0033d9e0 esi
extern "C" int __cdecl FUN_0033dad0(LuaVMState* L) {
    FUN_0033d9e0(L);
    FUN_00213720(L, -1);
    FUN_00213380(L, "__fenv", 6);
    FUN_00213600(L, -2);
    if (FUN_00212f00(L, -1) == LUAVM_TNIL)
        FUN_00212d80(L, -2);
    return 1;
}


// 0x0033db20 FUN_0033db20 (188 B): equivalent/0x0033db20.cpp
// sym: _FUN_0033db20 @7f1f06834950 @w1dd5291031bf
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_0033db20 @ 0x0033db20
// luaB_setfenv
// equiv-conv: FUN_0033d9e0 esi
extern "C" int __cdecl FUN_0033db20(LuaVMState* L) {
    FUN_00339d70(L, 2, LUAVM_TTABLE);
    FUN_0033d9e0(L);
    FUN_00213720(L, -1);
    FUN_00213380(L, "__fenv", 6);
    FUN_00213600(L, -2);
    if (FUN_00212f00(L, -1))
        FUN_00338e20(L, "`setfenv' cannot change a protected environment");
    else
        FUN_00212d80(L, -3);
    FUN_00212ed0(L, 2);
    if (FUN_00212f70(L, 1)) {
        if (FUN_002130e0(L, 1) == 0.0f) {
            FUN_00212e60(L, -10001);
            return 0;
        }
    }
    if (!FUN_00213950(L, -2))
        FUN_00338e20(L, "`setfenv' cannot change environment of given function");
    return 0;
}


// 0x0033dbe0 FUN_0033dbe0 (48 B): matches/0x0033dbe0.cpp
// sym: _FUN_0033dbe0
// luaB_rawequal
extern "C" int __cdecl FUN_0033dbe0(LuaVMState* L) {
    FUN_00339dc0(L, 1);
    FUN_00339dc0(L, 2);
    int x = FUN_00213010(L, 1, 2);
    FUN_00213520(L, x);
    return 1;
}


// 0x0033dc10 FUN_0033dc10 (41 B): matches/0x0033dc10.cpp
// sym: _FUN_0033dc10
// luaB_rawget
extern "C" int __cdecl FUN_0033dc10(LuaVMState* L) {
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    FUN_00339dc0(L, 2);
    FUN_00213600(L, 1);
    return 1;
}


// 0x0033dc40 FUN_0033dc40 (49 B): matches/0x0033dc40.cpp
// sym: _FUN_0033dc40
// luaB_rawset
extern "C" int __cdecl FUN_0033dc40(LuaVMState* L) {
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    FUN_00339dc0(L, 2);
    FUN_00339dc0(L, 3);
    FUN_00213800(L, 1);
    return 1;
}


// 0x0033dc80 FUN_0033dc80 (32 B): matches/0x0033dc80.cpp
// sym: _FUN_0033dc80
// luaB_gcinfo
extern "C" int __cdecl FUN_0033dc80(LuaVMState* L) {
    int v = FUN_00213ba0(L, 3, 0);
    FUN_00213360(L, v);
    return 1;
}


// 0x0033dca0 FUN_0033dca0 (183 B): equivalent/0x0033dca0.cpp
// sym: _FUN_0033dca0 @d05d6160cf49 @waf93b2cf5584
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_0033dca0 @ 0x0033dca0
// luaB_collectgarbage
// data: the option names = DAT_004350b4 (const char*[]), their lua_gc codes = DAT_004350a4 (int[])
extern "C" int __cdecl FUN_0033dca0(LuaVMState* L) {
    if (FUN_00212f70(L, 1)) {
        int value = FUN_00213120(L, 1);
        FUN_00212d80(L, 0);
        const char* option;
        if (value == 0) option = "collect";
        else if (value >= 10000) option = "stop";
        else option = "restart";
        FUN_002133d0(L, option);
    }
    const char* option = FUN_00339e60(L, 1, "collect", 0);
    int o = FUN_00338e50(option, (const char* const*)DAT_004350b4);
    int ex = FUN_00339fe0(L, 2, 0);
    if (o < 0) FUN_00339c30(L, 1, "invalid option");
    FUN_00213360(L, FUN_00213ba0(L, DAT_004350a4[o], ex));
    return 1;
}


// 0x0033dd60 FUN_0033dd60 (45 B): matches/0x0033dd60.cpp
// sym: _FUN_0033dd60
// luaB_type
extern "C" int __cdecl FUN_0033dd60(LuaVMState* L) {
    FUN_00339dc0(L, 1);
    FUN_002133d0(L, FUN_00212f20(L, FUN_00212f00(L, 1)));
    return 1;
}


// 0x0033dd90 FUN_0033dd90 (61 B): matches/0x0033dd90.cpp
// sym: _FUN_0033dd90
// luaB_next
extern "C" int __cdecl FUN_0033dd90(LuaVMState* L) {
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    FUN_00212d80(L, 2);
    if (FUN_00213c50(L, 1))
        return 2;
    FUN_00213320(L);
    return 1;
}


// 0x0033ddd0 FUN_0033ddd0 (55 B): matches/0x0033ddd0.cpp
// sym: _FUN_0033ddd0
// luaB_pairs
extern "C" int __cdecl FUN_0033ddd0(LuaVMState* L) {
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    FUN_002135a0(L, -10001, "next");
    FUN_00212ed0(L, 1);
    FUN_00213320(L);
    return 3;
}


// 0x0033de10 FUN_0033de10 (129 B): matches/0x0033de10.cpp
// sym: _FUN_0033de10
// luaB_ipairs
extern "C" int __cdecl FUN_0033de10(LuaVMState* L) {
    int n = FUN_00213120(L, 2);
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    if (n == 0 && FUN_00212f00(L, 2) == -1) {
        FUN_002135a0(L, -10001, "ipairs");
        FUN_00212ed0(L, 1);
        FUN_00213360(L, n);
        return 3;
    }
    n++;
    FUN_00213360(L, n);
    FUN_00213640(L, 1, n);
    return FUN_00212f00(L, -1) != 0 ? 2 : 0;
}


// 0x0033ded0 FUN_0033ded0 (88 B): matches/0x0033ded0.cpp
// sym: _FUN_0033ded0
// luaB_loadstring
extern "C" int __cdecl FUN_0033ded0(LuaVMState* L) {
    unsigned int l;
    const char* s = FUN_00339df0(L, 1, &l);
    const char* chunkname = FUN_00339e60(L, 2, s, 0);
    if (!FUN_00339a60(L, s, l, chunkname))
        return 1;
    FUN_00213320(L);
    FUN_00212e20(L, -2);
    return 2;
}


// 0x0033df30 FUN_0033df30 (62 B): matches/0x0033df30.cpp
// sym: _FUN_0033df30
// luaB_loadfile
extern "C" int __cdecl FUN_0033df30(LuaVMState* L) {
    const char* fname = FUN_00339e60(L, 1, 0, 0);
    int status = FUN_00339800(L, fname);
    if (status == 0)
        return 1;
    FUN_00213320(L);
    FUN_00212e20(L, -2);
    return 2;
}


// 0x0033df70 FUN_0033df70 (155 B): matches/0x0033df70.cpp
// sym: _FUN_0033df70
// generic_reader (luaB_load's lua_Reader): call the reader function, keep the piece it returns in the registry
// the original passes (res, LUA_REGISTRYINDEX) to luaL_unref in this order
extern "C" const char* __cdecl FUN_0033df70(LuaVMState* L, void* ud, unsigned int* size) {
    LuaVMLoadRefs* d = (LuaVMLoadRefs*)ud;
    FUN_00339710(L, d->res, -10000);
    FUN_00213640(L, -10000, d->func);
    FUN_002139a0(L, 0, 1);
    int t = FUN_00212f00(L, -1);
    if (!t) {
        *size = t;
        return 0;
    }
    if (FUN_00212fb0(L, -1)) {
        const char* s = FUN_00213190(L, -1);
        *size = FUN_002131f0(L, -1);
        d->res = FUN_00339650(L, -10000);
        return s;
    }
    FUN_00338e20(L, "reader function must return a string");
    return 0;
}


// 0x0033e010 FUN_0033e010 (167 B): matches/0x0033e010.cpp
// sym: _FUN_0033e010
// FUN_0033e010 @ 0x0033e010
// luaB_load
extern "C" int __cdecl FUN_0033e010(LuaVMState* L)
{
    LuaVMLoadRefs ls;
    const char* chunkname = FUN_00339e60(L, 2, "=(load)", 0);
    FUN_00339d70(L, 1, LUAVM_TFUNCTION);
    FUN_00212d80(L, 1);
    ls.func = FUN_00339650(L, -10000);
    ls.res = -1;
    int status = FUN_00213b20(L, FUN_0033df70, &ls, chunkname);
    FUN_00339710(L, ls.func, -10000);
    FUN_00339710(L, ls.res, -10000);
    if (status == 0)
        return 1;
    FUN_00213320(L);
    FUN_00212e20(L, -2);
    return 2;
}


// 0x0033e0c0 FUN_0033e0c0 (77 B): matches/0x0033e0c0.cpp
// sym: _FUN_0033e0c0
// luaB_dofile
extern "C" int __cdecl FUN_0033e0c0(LuaVMState* L) {
    const char* fname = FUN_00339e60(L, 1, 0, 0);
    int n = FUN_00212d70(L);
    if (FUN_00339800(L, fname))
        FUN_00213c40(L);
    FUN_002139a0(L, 0, -1);
    return FUN_00212d70(L) - n;
}


// 0x0033e110 FUN_0033e110 (77 B): matches/0x0033e110.cpp
// sym: _FUN_0033e110
// luaB_assert
extern "C" int __cdecl FUN_0033e110(LuaVMState* L) {
    FUN_00339dc0(L, 1);
    if (FUN_00213160(L, 1) == 0)
        return FUN_00338e20(L, "%s", FUN_00339e60(L, 2, "assertion failed!", 0));
    FUN_00212d80(L, 1);
    return 1;
}


// 0x0033e160 FUN_0033e160 (74 B): matches/0x0033e160.cpp
// sym: _FUN_0033e160
// luaB_unpack
extern "C" int __cdecl FUN_0033e160(LuaVMState* L) {
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    int n = FUN_003392c0(L, 1);
    FUN_00338fe0(L, n, "table too big to unpack");
    for (int i = 1; i <= n; ++i)
        FUN_00213640(L, 1, i);
    return n;
}


// 0x0033e1b0 FUN_0033e1b0 (70 B): equivalent/0x0033e1b0.cpp
// sym: _FUN_0033e1b0 @3489d266b356 @we111898ae02c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033e1b0 @ 0x0033e1b0
// luaB_pcall
extern "C" int __cdecl FUN_0033e1b0(LuaVMState* L) {
    FUN_00339dc0(L, 1);
    int status = FUN_002139f0(L, FUN_00212d70(L) - 1, -1, 0);
    FUN_00213520(L, status == 0);
    FUN_00212e20(L, 1);
    return FUN_00212d70(L);
}


// 0x0033e200 FUN_0033e200 (74 B): matches/0x0033e200.cpp
// sym: _FUN_0033e200
// luaB_xpcall
extern "C" int __cdecl FUN_0033e200(LuaVMState* L) {
    FUN_00339dc0(L, 2);
    FUN_00212d80(L, 2);
    FUN_00212e20(L, 1);
    int status = FUN_002139f0(L, 0, -1, 1);
    FUN_00213520(L, status == 0);
    FUN_00212e60(L, 1);
    return FUN_00212d70(L);
}


// 0x0033e3f0 FUN_0033e3f0 (212 B): equivalent/0x0033e3f0.cpp
// sym: _FUN_0033e3f0 @b5c0fcbd200d @wf38db5a15c13
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_0033e3f0 @ 0x0033e3f0
// luaB_newproxy
extern "C" int __cdecl FUN_0033e3f0(LuaVMState* state)
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


// 0x0033e4d0 FUN_0033e4d0 (51 B): equivalent/0x0033e4d0.cpp
// sym: ?FUN_0033e4d0@fn_fc191ef1@@YAPBDPAULuaVMState@@@Z @d90dc0d73226 @w3ea818cff1d2
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033e4d0 @ 0x0033e4d0
// lbaselib getpath: LUA_PATH or the default
// equiv-conv: FUN_0033e4d0 esi
const char* FUN_0033e4d0(LuaVMState* L)
{
    FUN_002135a0(L, -10001, "LUA_PATH");
    const char* path = FUN_00213190(L, -1);
    FUN_00212d80(L, -2);
    return path ? path : "?;?.lua";
}


// 0x0033e570 FUN_0033e570 (112 B): equivalent/0x0033e570.cpp
// sym: ?FUN_0033e570@fn_fc191ef1@@YAXPAULuaVMState@@@Z @43b4ece3ec7f @w816e1483fdc6
// STATUS: equivalent (tools/equiv.py level 3: 2564 inputs, branch coverage 4/4)
// FUN_0033e570 @ 0x0033e570
// lbaselib composename: replace each `?' of the path piece on the top by the required name
// equiv-conv: FUN_0033e570 ebx
void FUN_0033e570(LuaVMState *L)
{
    const char *s = FUN_00213190(L, -1);
    int pieces = 1;
    const char *mark = strchr(s, '?');
    while (mark != 0) {
        FUN_00338fe0(L, 3, "too many marks in a path component");
        FUN_00213380(L, s, (unsigned int)(mark - s));
        FUN_00212ed0(L, 1);
        s = mark + 1;
        pieces += 2;
        mark = strchr(s, '?');
    }
    FUN_002133d0(L, s);
    FUN_00213c90(L, pieces);
}


// 0x0033e5e0 FUN_0033e5e0 (517 B): equivalent/0x0033e5e0.cpp
// sym: _FUN_0033e5e0 @dea1e351ef14 @wc617d15d0f10
// STATUS: equivalent (tools/equiv.py level 3: 3081 inputs, branch coverage 23/24, incomplete)
// FUN_0033e5e0 @ 0x0033e5e0
// luaB_require
// equiv-conv: FUN_0033e570 ebx
// equiv-conv: FUN_0033e4d0 esi
extern "C" int __cdecl FUN_0033e5e0(LuaVMState* state) {
 int status=2;
 FUN_00339df0(state,1,0);
 FUN_00212d80(state,1);
 FUN_002135a0(state,-10001,"_LOADED");
 if(FUN_00212f00(state,2)!=5) return FUN_00338e20(state,"`_LOADED' is not a table");
 FUN_002135a0(state,-10001,"LUA_PATH");
 const char* path=FUN_00213190(state,-1);
 FUN_00212d80(state,-2);
 if(!path) path="?;?.lua";
 FUN_00212ed0(state,1);
 FUN_00213600(state,2);
 if(FUN_00213160(state,-1)) return 1;
 do {
  FUN_00212d80(state,3);
  if(!*path) break;
  const char* start=path;
  if(*start==';') ++start;
  path=strchr(start,';');
  if(!path) { path=start; while(*path) ++path; }
  FUN_00213380(state,start,(unsigned)(path-start));
  if(!path) break;
  FUN_0033e570(state);
  const char* filename=FUN_00213190(state,-1);
  status=FUN_00339800(state,filename);
 } while(status==2);
 if(status!=0) {
  const char* detail;
  if(status==2) detail=FUN_0033e4d0(state);
  else detail=FUN_00213190(state,-1);
  const char* package=FUN_00213190(state,1);
  if(status==2) return FUN_00338e20(state,"could not load package `%s' from path `%s'",package,detail);
  return FUN_00338e20(state,"error loading package `%s' (%s)",package,detail);
 }
 FUN_002135a0(state,-10001,"_REQUIREDNAME");
 FUN_00212e20(state,-2);
 FUN_00212ed0(state,1);
 FUN_00213790(state,-10001,"_REQUIREDNAME");
 FUN_002139a0(state,0,1);
 FUN_00212e20(state,-2);
 FUN_00213790(state,-10001,"_REQUIREDNAME");
 if(!FUN_00212f00(state,-1)) {
  FUN_00213520(state,1);
  FUN_00212e60(state,-2);
 }
 FUN_00212ed0(state,1);
 FUN_00212ed0(state,-2);
 FUN_00213800(state,2);
 return 1;
}


// 0x0033e7f0 FUN_0033e7f0 (121 B): equivalent/0x0033e7f0.cpp
// sym: ?FUN_0033e7f0@fn_fc191ef1@@YAHHPAULuaVMState@@0@Z @732dfa594d51 @w11f8a7fc63f9
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0033e7f0 @ 0x0033e7f0
// Lua 5.0 coroutine auxresume: eax = number of arguments, esi = coroutine, edi = caller state.
           // luaL_error
// equiv-conv: FUN_0033e7f0 eax esi edi
int FUN_0033e7f0(int narg, LuaVMState* co, LuaVMState* L) {
    if (!FUN_00212c50(co, narg))
        FUN_00338e20(L, "too many arguments to resume");
    FUN_00212cb0(L, co, narg);
    int status = FUN_00215d10(co, narg);
    if (status == 0) {
        int nres = FUN_00212d70(co);
        if (!FUN_00212c50(L, nres))
            FUN_00338e20(L, "too many results to resume");
        FUN_00212cb0(co, L, nres);
        return nres;
    }
    FUN_00212cb0(co, L, 1);
    return -1;
}


// 0x0033e870 FUN_0033e870 (116 B): equivalent/0x0033e870.cpp
// sym: _FUN_0033e870 @4a3fa8f2da3c @wba14ef3062ac
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0033e870 @ 0x0033e870
// luaB_coresume
// equiv-conv: FUN_0033e7f0 eax esi edi
extern "C" int __cdecl FUN_0033e870(LuaVMState *L)
{
    LuaVMState *co = FUN_00213290(L, 1);
    if (co == 0)
        FUN_00339c30(L, 1, "coroutine expected");
    int r = FUN_0033e7f0(FUN_00212d70(L) - 1, co, L);
    if (r < 0) {
        FUN_00213520(L, 0);
        FUN_00212e20(L, -2);
        return 2;
    }
    FUN_00213520(L, 1);
    FUN_00212e20(L, -(r + 1));
    return r + 1;
}


// 0x0033e8f0 FUN_0033e8f0 (95 B): equivalent/0x0033e8f0.cpp
// sym: _FUN_0033e8f0 @aef5ed9b0b99 @w5712dbddd8fe
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0033e8f0 @ 0x0033e8f0
// luaB_auxwrap (upvalue 1: the coroutine)
// equiv-conv: FUN_0033e7f0 eax esi edi
extern "C" int __cdecl FUN_0033e8f0(LuaVMState* L) {
    LuaVMState* co = FUN_00213290(L, -10002);
    int r = FUN_0033e7f0(FUN_00212d70(L), co, L);
    if (r < 0) {
        if (FUN_00212fb0(L, -1)) {
            FUN_00338d90(L, 1);
            FUN_00212e20(L, -2);
            FUN_00213c90(L, 2);
        }
        FUN_00213c40(L);
    }
    return r;
}


// 0x0033e950 FUN_0033e950 (89 B): matches/0x0033e950.cpp
// sym: _FUN_0033e950
// luaB_cocreate
// data: luaerr = DAT_00435268
extern "C" int __cdecl FUN_0033e950(LuaVMState* L) {
    LuaVMState* NL = FUN_00212d30(L);
    int t = FUN_00212f00(L, 1);
    if (t != LUAVM_TFUNCTION || FUN_00212f40(L, 1) != 0)
        FUN_00339c30(L, 1, DAT_00435268);
    FUN_00212ed0(L, 1);
    FUN_00212cb0(L, NL, 1);
    return 1;
}


// 0x0033e9b0 FUN_0033e9b0 (34 B): matches/0x0033e9b0.cpp
// sym: _FUN_0033e9b0
// luaB_cowrap
extern "C" int __cdecl FUN_0033e9b0(LuaVMState* L) {
    FUN_0033e950(L);
    FUN_002134a0(L, FUN_0033e8f0, 1);
    return 1;
}


// 0x0033e9e0 FUN_0033e9e0 (23 B): matches/0x0033e9e0.cpp
// sym: _FUN_0033e9e0
// luaB_yield
extern "C" int __cdecl FUN_0033e9e0(LuaVMState* L) {
    return FUN_00215b60(L, FUN_00212d70(L));
}


// 0x0033ea90 FUN_0033ea90 (150 B): equivalent/0x0033ea90.cpp
// sym: ?FUN_0033ea90@fn_fc191ef1@@YAXPAULuaVMState@@@Z @5170c83aff98 @wf8cfc29d7da4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0033ea90 @ 0x0033ea90
// luaopen_base's base_open: the state is passed in esi
// data: base_funcs = DAT_00434d90 (luaL_reg[])
// equiv-conv: FUN_0033ea90 esi
void FUN_0033ea90(LuaVMState *L)
{
    FUN_00212ed0(L, -10001);
    FUN_003390d0(L, 0, (const LuaVMReg *)&DAT_00434d90, 0);
    FUN_00213380(L, "Lua 5.1 (work)", 14);
    FUN_00213790(L, -2, "_VERSION");
    FUN_00213680(L, 0, 0);
    FUN_00212ed0(L, -1);
    FUN_002138e0(L, -2);
    FUN_00213380(L, "kv", 2);
    FUN_00213790(L, -2, "__mode");
    FUN_002134a0(L, FUN_0033e3f0, 1);
    FUN_00213790(L, -2, "newproxy");
    FUN_00213790(L, -1, "_G");
}


// 0x0033eb30 FUN_0033eb30 (64 B): equivalent/0x0033eb30.cpp
// sym: _FUN_0033eb30 @df024c7fef2a @w18a6475511b8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0033eb30 @ 0x0033eb30
// luaopen_base
// data: s_coroutine = DAT_0042257c, co_funcs = DAT_00434e68 (luaL_reg[]), s_LOADED = DAT_00435210
// equiv-conv: FUN_0033ea90 esi
extern "C" int __cdecl FUN_0033eb30(LuaVMState* L) {
    FUN_0033ea90(L);
    FUN_003390d0(L, DAT_0042257c, (const LuaVMReg*)DAT_00434e68, 0);
    FUN_00213680(L, 0, 0);
    FUN_00213790(L, -10001, DAT_00435210);
    return 2;
}

} // namespace fn_fc191ef1

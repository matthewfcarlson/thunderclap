// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0033acd0..0x0033b610 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_ff2a2ef6 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff2a2ef6 {} using namespace fn_ff2a2ef6;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_ff2a2ef6 {
extern "C" void __cdecl FUN_00212d80(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00212ed0(LuaVMState *L, int idx);
extern "C" int __cdecl FUN_00212f00(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00213360(LuaVMState *L, int n);
extern "C" void __cdecl FUN_00213640(LuaVMState *L, int idx, int n);
extern "C" void __cdecl FUN_002139a0(LuaVMState *L, int nargs, int nresults);
extern "C" int __cdecl FUN_003392c0(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00339d70(LuaVMState *L, int idx, int type);
extern "C" void __cdecl FUN_00213320(LuaVMState*);
extern "C" int __cdecl FUN_00213c50(LuaVMState*, int);
extern "C" int __cdecl FUN_00339f70(LuaVMState*, int);
extern "C" void __cdecl FUN_00339270(LuaVMState*, int, int);
extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_00213870(LuaVMState*, int, int);
extern "C" int __cdecl FUN_00339fe0(LuaVMState* L, int idx, int def);
extern "C" void __cdecl FUN_00338fe0(LuaVMState*, int, const char*);
extern "C++" __declspec(nothrow) void __cdecl FUN_0033b110(LuaVMState*, int, int);
extern "C" void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);


// 0x0033acd0 FUN_0033acd0 (129 B): matches/0x0033acd0.cpp
// sym: _FUN_0033acd0
// FUN_0033acd0 @ 0x0033acd0
// Calls the function in argument 2 on each element (index, value) of the table in argument 1
// and returns 1 as soon as it answers true, otherwise 0.
extern "C" int __cdecl FUN_0033acd0(LuaVMState *L)
{
    FUN_00339d70(L, 1, 5);
    int n = FUN_003392c0(L, 1);
    FUN_00339d70(L, 2, 6);
    for (int i = 1; i <= n; i++) {
        FUN_00212ed0(L, 2);
        FUN_00213360(L, i);
        FUN_00213640(L, 1, i);
        FUN_002139a0(L, 2, 1);
        if (FUN_00212f00(L, -1))
            return 1;
        FUN_00212d80(L, -2);
    }
    return 0;
}


// 0x0033ad60 FUN_0033ad60 (131 B): matches/0x0033ad60.cpp
// sym: _FUN_0033ad60
// foreach
extern "C" int __cdecl FUN_0033ad60(LuaVMState* p) {
    FUN_00339d70(p, 1, 5);
    FUN_00339d70(p, 2, 6);
    FUN_00213320(p);
    int i = FUN_00213c50(p, 1);
    while (i) {
        FUN_00212ed0(p, 2);
        FUN_00212ed0(p, -3);
        FUN_00212ed0(p, -3);
        FUN_002139a0(p, 2, 1);
        i = FUN_00212f00(p, -1);
        if (i)
            return 1;
        FUN_00212d80(p, -3);
        i = FUN_00213c50(p, 1);
    }
    return 0;
}


// 0x0033adf0 FUN_0033adf0 (40 B): matches/0x0033adf0.cpp
// sym: _FUN_0033adf0
// luaB_getn
extern "C" int __cdecl FUN_0033adf0(LuaVMState* p) {
    FUN_00339d70(p, 1, 5);
    int x = FUN_003392c0(p, 1);
    FUN_00213360(p, x);
    return 1;
}


// 0x0033ae20 FUN_0033ae20 (39 B): matches/0x0033ae20.cpp
// sym: _FUN_0033ae20
// luaB_setn
extern "C" int __cdecl FUN_0033ae20(LuaVMState* a) {
    FUN_00339d70(a, 1, 5);
    int v = FUN_00339f70(a, 2);
    FUN_00339270(a, 1, v);
    return 0;
}


// 0x0033ae50 FUN_0033ae50 (151 B): matches/0x0033ae50.cpp
// sym: _FUN_0033ae50
// luaB_tinsert
extern "C" int __cdecl FUN_0033ae50(LuaVMState* p) {
    int b = FUN_00212d70(p);
    FUN_00339d70(p, 1, 5);
    int s = FUN_003392c0(p, 1) + 1;
    int e;
    if (b == 2)
        e = s;
    else {
        e = FUN_00339f70(p, 2);
        if (e > s)
            s = e;
        b = 3;
    }
    FUN_00339270(p, 1, s);
    --s;
    while (s >= e) {
        FUN_00213640(p, 1, s);
        FUN_00213870(p, 1, s + 1);
        --s;
    }
    FUN_00212ed0(p, b);
    FUN_00213870(p, 1, e);
    return 0;
}


// 0x0033aef0 FUN_0033aef0 (138 B): matches/0x0033aef0.cpp
// sym: _FUN_0033aef0
// FUN_0033aef0 @ 0x0033aef0
// tremove
extern "C" int __cdecl FUN_0033aef0(LuaVMState* L) {
    FUN_00339d70(L, 1, 5);
    int n = FUN_003392c0(L, 1);
    int pos = FUN_00339fe0(L, 2, n);
    if (n <= 0) return 0;
    FUN_00339270(L, 1, n - 1);
    FUN_00213640(L, 1, pos);
    for (; pos < n; pos++) {
        FUN_00213640(L, 1, pos + 1);
        FUN_00213870(L, 1, pos);
    }
    FUN_00213320(L);
    FUN_00213870(L, 1, n);
    return 1;
}

} // namespace fn_ff2a2ef6

// 0x0033b110 FUN_0033b110 (995 B): equivalent/0x0033b110.cpp [wrapped: macros]
// sym: _FUN_0033b110
namespace fn_0033b110 {
// STATUS: equivalent (tools/equiv.py level 3: 315 inputs, branch coverage 35/36, incomplete)
// FUN_0033b110 @ 0x0033b110
// auxsort

extern "C++" __declspec(nothrow) void __cdecl FUN_00213640(LuaVMState *L, int idx, int n);
extern "C++" __declspec(nothrow) int __cdecl FUN_00212f00(LuaVMState *L, int idx);
extern "C++" __declspec(nothrow) void __cdecl FUN_00212ed0(LuaVMState *L, int idx);
extern "C++" __declspec(nothrow) void __cdecl FUN_002139a0(LuaVMState *L, int nargs, int nresults);
extern "C" int __cdecl FUN_00213160(LuaVMState *L, int idx);
extern "C++" __declspec(nothrow) void __cdecl FUN_00212d80(LuaVMState *L, int idx);
extern "C" int __cdecl FUN_002130a0(LuaVMState *L, int a, int b);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213870(LuaVMState *L, int idx, int n);
extern "C" int __cdecl FUN_00338e20(LuaVMState *L, const char *fmt, ...);

#define SORT_COMP(res, L, a, b) \
    do { \
        if (FUN_00212f00(L, 2)) { \
            FUN_00212ed0(L, 2); \
            FUN_00212ed0(L, (a) - 1); \
            FUN_00212ed0(L, (b) - 2); \
            FUN_002139a0(L, 2, 1); \
            res = FUN_00213160(L, -1); \
            FUN_00212d80(L, -2); \
        } else { \
            res = FUN_002130a0(L, a, b); \
        } \
    } while (0)

extern "C" void __cdecl FUN_0033b110(LuaVMState *L, int l, int u)
{
    while (l < u) {
        int i, j, r;
        FUN_00213640(L, 1, l);
        FUN_00213640(L, 1, u);
        SORT_COMP(r, L, -1, -2);
        if (r) {
            FUN_00213870(L, 1, l);
            FUN_00213870(L, 1, u);
        } else {
            FUN_00212d80(L, -3);
        }
        if (u - l == 1)
            break;
        i = (l + u) / 2;
        FUN_00213640(L, 1, i);
        FUN_00213640(L, 1, l);
        SORT_COMP(r, L, -2, -1);
        if (r) {
            FUN_00213870(L, 1, i);
            FUN_00213870(L, 1, l);
        } else {
            FUN_00212d80(L, -2);
            FUN_00213640(L, 1, u);
            SORT_COMP(r, L, -1, -2);
            if (r) {
                FUN_00213870(L, 1, i);
                FUN_00213870(L, 1, u);
            } else {
                FUN_00212d80(L, -3);
            }
        }
        if (u - l == 2)
            break;
        FUN_00213640(L, 1, i);
        FUN_00212ed0(L, -1);
        FUN_00213640(L, 1, u - 1);
        FUN_00213870(L, 1, i);
        FUN_00213870(L, 1, u - 1);
        i = l;
        j = u - 1;
        for (;;) {
            for (;;) {
                FUN_00213640(L, 1, ++i);
                SORT_COMP(r, L, -1, -2);
                if (!r)
                    break;
                if (i > u)
                    FUN_00338e20(L, "invalid order function for sorting");
                FUN_00212d80(L, -2);
            }
            for (;;) {
                FUN_00213640(L, 1, --j);
                SORT_COMP(r, L, -3, -1);
                if (!r)
                    break;
                if (j < l)
                    FUN_00338e20(L, "invalid order function for sorting");
                FUN_00212d80(L, -2);
            }
            if (j < i) {
                FUN_00212d80(L, -4);
                break;
            }
            FUN_00213870(L, 1, i);
            FUN_00213870(L, 1, j);
        }
        FUN_00213640(L, 1, u - 1);
        FUN_00213640(L, 1, i);
        FUN_00213870(L, 1, u - 1);
        FUN_00213870(L, 1, i);
        if (i - l < u - i) {
            j = l;
            i = i - 1;
            l = i + 2;
        } else {
            j = i + 1;
            i = u;
            u = j - 2;
        }
        FUN_0033b110(L, j, i);
    }
}
} // namespace fn_0033b110
#undef SORT_COMP

namespace fn_ff2a2ef6 {

// 0x0033b500 FUN_0033b500 (92 B): matches/0x0033b500.cpp
// sym: _FUN_0033b500
// luaB_sort
// data: gZero_33b500 = DAT_003f335c
extern "C" int __cdecl FUN_0033b500(LuaVMState* p) {
    FUN_00339d70(p, 1, 5);
    int v = FUN_003392c0(p, 1);
    FUN_00338fe0(p, 0x28, (const char*)&DAT_003f335c);
    int n = FUN_00212f00(p, 2);
    if (n > 0)
        FUN_00339d70(p, 2, 6);
    FUN_00212d80(p, 2);
    FUN_0033b110(p, 1, v);
    return 0;
}


// 0x0033b560 FUN_0033b560 (31 B): matches/0x0033b560.cpp
// sym: _FUN_0033b560
// luaopen_table
extern "C" int __cdecl FUN_0033b560(LuaVMState* p) {
    FUN_003390d0(p, "table", (const LuaVMReg*)DAT_004348a0, 0);
    return 1;
}

} // namespace fn_ff2a2ef6

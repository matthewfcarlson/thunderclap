// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0033a080..0x0033acd0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f497c4d2 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f497c4d2 {} using namespace fn_f497c4d2;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f497c4d2 {
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
extern "C" int __cdecl FUN_00212f40(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213dd0(LuaVMState* L, int funcindex, int n);
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00212e20(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" const char* __cdecl FUN_00213e50(LuaVMState* L, int funcindex, int n);
extern "C" {
void __cdecl FUN_00213550(LuaVMState* L, void* p);
}
extern "C" {
void __cdecl FUN_00213600(LuaVMState* L, int i);
}
extern "C" {
int __cdecl FUN_00212f00(LuaVMState* L, int i);
}
extern "C" {
void __cdecl FUN_00213360(LuaVMState* L, int n);
}
extern "C" {
void __cdecl FUN_00213320(LuaVMState* L);
}
extern "C" {
void __cdecl FUN_002139a0(LuaVMState* L, int a, int b);
}
extern "C" void __cdecl FUN_00212d80(LuaVMState *, int);
extern "C" void __cdecl FUN_00213680(LuaVMState *, int, int);
extern "C" void __cdecl FUN_00212ed0(LuaVMState *, int);
extern "C" void __cdecl FUN_00213800(LuaVMState *, int);
extern "C" LuaVMState* __cdecl FUN_00213290(LuaVMState*,int);
extern "C" void __cdecl FUN_0033a620(LuaVMState* L, LuaVMDebug* ar);
extern "C" int __cdecl FUN_00213f60(LuaVMState*,LuaVMHook,int,int);
extern "C" const char* __cdecl FUN_00339df0(LuaVMState*,int,unsigned int*);
extern "C" int __cdecl FUN_00339fe0(LuaVMState*,int,int);
extern "C" int __cdecl FUN_0033a6b0(const char*,int);
extern "C" void __cdecl FUN_0033a740(LuaVMState*);
extern "C" void __cdecl FUN_00212cb0(LuaVMState*,LuaVMState*,int);
extern "C" unsigned int DAT_004d9968;
extern "C" {
int __cdecl FUN_00213fa0(LuaVMState*);
}
extern "C" {
LuaVMHook __cdecl FUN_00213f90(LuaVMState*);
}
extern "C" {
void __cdecl FUN_00213380(LuaVMState*, const char*, unsigned int);
}
extern "C" {
void __cdecl FUN_00212de0(LuaVMState*, int);
}
extern "C" {
int __cdecl FUN_00213fb0(LuaVMState*);
}
extern "C" void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
extern "C" int __cdecl FUN_0033aa40(LuaVMState* L);


// 0x0033a560 FUN_0033a560 (88 B): matches/0x0033a560.cpp
// sym: _FUN_0033a560
// db_getupvalue
extern "C" int __cdecl FUN_0033a560(LuaVMState* p) {
    int v = FUN_00339f70(p, 2);
    FUN_00339d70(p, 1, 6);
    if (FUN_00212f40(p, 1) != 0)
        return 0;
    const char* r = FUN_00213dd0(p, 1, v);
    if (r == 0)
        return 0;
    FUN_002133d0(p, r);
    FUN_00212e20(p, -2);
    return 2;
}


// 0x0033a5c0 FUN_0033a5c0 (96 B): matches/0x0033a5c0.cpp
// sym: _FUN_0033a5c0
// db_setupvalue
extern "C" int __cdecl FUN_0033a5c0(LuaVMState* self) {
    int edi;
    FUN_00339dc0(self, 3);
    edi = FUN_00339f70(self, 2);
    FUN_00339d70(self, 1, 6);
    if (FUN_00212f40(self, 1) != 0)
        return 0;
    const char* r = FUN_00213e50(self, 1, edi);
    if (r == 0)
        return 0;
    FUN_002133d0(self, r);
    FUN_00212e20(self, -1);
    return 1;
}


// 0x0033a620 FUN_0033a620 (139 B): matches/0x0033a620.cpp
// sym: _FUN_0033a620
// hookf: the debug library's hook (a LuaVMHook): calls the hook table's function of this thread with
// (event name, current line or nil).
// data: g_key = DAT_00434708, g_names = DAT_00434864
extern "C" void __cdecl FUN_0033a620(LuaVMState* L, LuaVMDebug* ar) {
    FUN_00213550(L, (void*)DAT_00434708);
    FUN_00213600(L, -10000);
    FUN_00213550(L, L);
    FUN_00213600(L, -2);
    if (FUN_00212f00(L, -1) == 6) {
        FUN_002133d0(L, ((const char* const*)&DAT_00434864)[ar->event]);
        if (ar->currentline >= 0) {
            FUN_00213360(L, ar->currentline);
        } else {
            FUN_00213320(L);
        }
        FUN_002139a0(L, 2, 0);
    }
}


// 0x0033a6b0 FUN_0033a6b0 (74 B): equivalent/0x0033a6b0.cpp
// sym: _FUN_0033a6b0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0033a6b0 @ 0x0033a6b0
// makemask
// equiv-conv: FUN_0033a6b0 edi stack
extern "C" int __cdecl FUN_0033a6b0(const char* text, int count)
{
    int flags = 0;
    if (strchr(text, 'c')) flags |= 1;
    if (strchr(text, 'r')) flags |= 2;
    if (strchr(text, 'l')) flags |= 4;
    if (count > 0) flags |= 8;
    return flags;
}


// 0x0033a740 FUN_0033a740 (90 B): equivalent/0x0033a740.cpp
// sym: _FUN_0033a740
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 2/2)
// FUN_0033a740 @ 0x0033a740
// gethooktable: pushes registry[KEY_HOOK] (created on first use).
// equiv-conv: FUN_0033a740 esi
extern "C" void __cdecl FUN_0033a740(LuaVMState *context)
{
    FUN_00213550(context, ((void*)&DAT_00434708));
    FUN_00213600(context, -10000);
    if (FUN_00212f00(context, -1) != 5) {
        FUN_00212d80(context, -2);
        FUN_00213680(context, 0, 0);
        FUN_00213550(context, ((void*)&DAT_00434708));
        FUN_00212ed0(context, -2);
        FUN_00213800(context, -10000);
    }
}


// 0x0033a7a0 FUN_0033a7a0 (215 B): equivalent/0x0033a7a0.cpp
// sym: _FUN_0033a7a0
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_0033a7a0 @ 0x0033a7a0
// db_sethook
// equiv-conv: FUN_0033a6b0 edi stack
// equiv-conv: FUN_0033a740 esi
extern "C" int __cdecl FUN_0033a7a0(LuaVMState* state) {
 int offset=0; LuaVMState* context=state;
 if(FUN_00212f00(state,1)==8){offset=1; context=FUN_00213290(state,1);}
 int index=offset+1;
 if(FUN_00212f00(state,index)<=0){FUN_00212d80(state,index); FUN_00213f60(context,0,0,0);}
 else {const char* first=FUN_00339df0(state,offset+2,0); int second=FUN_00339fe0(state,offset+3,0); FUN_00339d70(state,index,6); int result=FUN_0033a6b0(first,second); FUN_00213f60(context,FUN_0033a620,result,second);}
 FUN_0033a740(context); FUN_00213550(context,context); FUN_00212ed0(state,index); FUN_00212cb0(state,context,1); FUN_00213800(context,-3); FUN_00212d80(context,-2); return 0;
}


// 0x0033a880 FUN_0033a880 (230 B): equivalent/0x0033a880.cpp
// sym: _FUN_0033a880
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 12/12)
// FUN_0033a880 @ 0x0033a880
// db_gethook
// equiv-conv: FUN_0033a740 esi
extern "C" int __cdecl FUN_0033a880(LuaVMState* state) {
unsigned int cookie=DAT_004d9968;
LuaVMState* source = state;
if (FUN_00212f00(state,1)==8) source=FUN_00213290(state,1);
int flags=FUN_00213fa0(source);
LuaVMHook hook=FUN_00213f90(source);
if(hook && hook != FUN_0033a620) {
FUN_00213380(state,"external hook",13);
} else {
FUN_0033a740(source);
FUN_00213550(source,source);
FUN_00213600(source,-2);
FUN_00212de0(source,-2);
FUN_00212cb0(source,state,1);
}
char mode[4]; int count=0;
if(flags&1) mode[count++]='c';
if(flags&2) mode[count++]='r';
if(flags&4) mode[count++]='l';
mode[count]=0;
FUN_002133d0(state,mode);
int value=FUN_00213fb0(source);
FUN_00213360(state,value);
__security_check_cookie(cookie);
return 3;
}


// 0x0033ac90 FUN_0033ac90 (62 B): matches/0x0033ac90.cpp
// sym: _FUN_0033ac90
// luaopen_debug
extern "C" int __cdecl FUN_0033ac90(LuaVMState* p) {
    FUN_003390d0(p, "debug", ((const LuaVMReg*)&DAT_00434710), 0);
    FUN_002134a0(p, FUN_0033aa40, 0);
    FUN_00213790(p, -10001, "_TRACEBACK");
    return 1;
}

} // namespace fn_f497c4d2

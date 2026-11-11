// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0033a080..0x0033acd0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/core.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f85c1dd7 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f85c1dd7 {} using namespace fn_f85c1dd7;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f85c1dd7 {
extern "C" int __cdecl FUN_00212f00(LuaVMState *L, int idx);
extern "C" LuaVMState *__cdecl FUN_00213290(LuaVMState *L, int idx);
extern "C" const char *__cdecl FUN_00339e60(LuaVMState *L, int narg, const char *def, unsigned int *len);
extern "C" int __cdecl FUN_00212f70(LuaVMState *L, int idx);
extern "C" int __cdecl FUN_00213120(LuaVMState *L, int idx);
extern "C" int __cdecl FUN_00213fc0(LuaVMState *L, int level, LuaVMDebug *ar);
extern "C" void __cdecl FUN_00213320(LuaVMState *L);
extern "C" const char *__cdecl FUN_00213470(LuaVMState *L, const char *fmt, ...);
extern "C" const char *__cdecl FUN_00213190(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00212ed0(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00212cb0(LuaVMState *from, LuaVMState *to, int n);
extern "C" int __cdecl FUN_00214bd0(LuaVMState *L, const char *what, LuaVMDebug *ar);
extern "C" int __cdecl FUN_00339c30(LuaVMState *L, int narg, const char *msg);
extern "C" void __cdecl FUN_00213680(LuaVMState *L, int narr, int nrec);
extern "C" void __cdecl FUN_002133d0(LuaVMState *L, const char *s);
extern "C" void __cdecl FUN_00213360(LuaVMState *L, int n);
extern "C" void __cdecl FUN_00213790(LuaVMState *L, int idx, const char *k);
extern "C" int __cdecl FUN_00339f70(LuaVMState*, int);
extern "C" const char* __cdecl FUN_00214050(LuaVMState*, LuaVMDebug*, int);
extern "C" void __cdecl FUN_00339dc0(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
extern "C" const char* __cdecl FUN_002140c0(LuaVMState*, LuaVMDebug*, int);
extern "C" LuaVMFile DAT_004d99f0;
extern "C" int __cdecl FUN_00347eed(const char *, LuaVMFile *);
} // namespace fn_f85c1dd7
extern "C" char * __cdecl _fgets(char *, int, LuaVMFile *);
namespace fn_f85c1dd7 {
extern "C" int __cdecl FUN_00339c00(LuaVMState *L, const char *str);
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" int __cdecl FUN_00212fb0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" void __cdecl FUN_00213c90(LuaVMState* L, int n);
struct Frame_33aa40 {
    int arg;
    int firstpart;
    LuaVMDebug ar;
};


// 0x0033a080 FUN_0033a080 (638 B): equivalent/0x0033a080.cpp
// sym: _FUN_0033a080
// STATUS: equivalent (tools/equiv.py level 3: 3098 inputs, branch coverage 23/24, incomplete)
// FUN_0033a080 @ 0x0033a080
// db_getinfo
extern "C" int __cdecl FUN_0033a080(LuaVMState *L)
{
    LuaVMDebug ar;
    LuaVMState *L1;
    int arg;
    if (FUN_00212f00(L, 1) == 8) {
        arg = 1;
        L1 = FUN_00213290(L, 1);
    } else {
        arg = 0;
        L1 = L;
    }
    const char *options = FUN_00339e60(L, arg + 2, "flnSu", 0);
    if (FUN_00212f70(L, arg + 1)) {
        if (!FUN_00213fc0(L1, FUN_00213120(L, arg + 1), &ar)) {
            FUN_00213320(L);
            return 1;
        }
    } else if (FUN_00212f00(L, arg + 1) == 6) {
        FUN_00213470(L, ">%s", options);
        options = FUN_00213190(L, -1);
        FUN_00212ed0(L, arg + 1);
        FUN_00212cb0(L, L1, 1);
    } else {
        int r = FUN_00339c30(L, arg + 1, "function or level expected");
        return r;
    }
    if (!FUN_00214bd0(L1, options, &ar)) {
        int r = FUN_00339c30(L, arg + 2, "invalid option");
        return r;
    }
    FUN_00213680(L, 0, 0);
    for (; *options; options++) {
        switch (*options) {
        case 'S':
            FUN_002133d0(L, ar.source);
            FUN_00213790(L, -2, "source");
            FUN_002133d0(L, ar.short_src);
            FUN_00213790(L, -2, "short_src");
            FUN_00213360(L, ar.linedefined);
            FUN_00213790(L, -2, "linedefined");
            FUN_002133d0(L, ar.what);
            FUN_00213790(L, -2, "what");
            break;
        case 'l':
            FUN_00213360(L, ar.currentline);
            FUN_00213790(L, -2, "currentline");
            break;
        case 'u':
            FUN_00213360(L, ar.nups);
            FUN_00213790(L, -2, "nups");
            break;
        case 'n':
            FUN_002133d0(L, ar.name);
            FUN_00213790(L, -2, "name");
            FUN_002133d0(L, ar.namewhat);
            FUN_00213790(L, -2, "namewhat");
            break;
        case 'f':
            if (L == L1)
                FUN_00212ed0(L, -2);
            else
                FUN_00212cb0(L1, L, 1);
            FUN_00213790(L, -2, "func");
            break;
        default:
            break;
        }
    }
    return 1;
}


// 0x0033a340 FUN_0033a340 (234 B): equivalent/0x0033a340.cpp
// sym: _FUN_0033a340
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 6/6)
// FUN_0033a340 @ 0x0033a340
// db_getlocal
extern "C" int __cdecl FUN_0033a340(LuaVMState* state) {
 LuaVMDebug ar;
 LuaVMState* other = state;
 int base = 0;
 if (FUN_00212f00(state,1)==8) { base=1; other=FUN_00213290(state,1); }
 int level=FUN_00339f70(state,base+1);
 int ok=FUN_00213fc0(other,level,&ar);
 int ret;
 if (!ok) ret=FUN_00339c30(state,base+1,"level out of range");
 else {
 int item=FUN_00339f70(state,base+2);
 const char* result=FUN_00214050(other,&ar,item);
 if(result) {
 FUN_00212cb0(other,state,1);
 FUN_002133d0(state,result);
 FUN_00212ed0(state,-2);
 ret=2;
 } else {
 FUN_00213320(state);
 ret=1;
 }
 }
 return ret;
}


// 0x0033a430 FUN_0033a430 (206 B): equivalent/0x0033a430.cpp
// sym: _FUN_0033a430
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_0033a430 @ 0x0033a430
// db_setlocal
extern "C" int __cdecl FUN_0033a430(LuaVMState* state) {
 LuaVMDebug ar;
 int offset = 0;
 LuaVMState* object = state;
 if (FUN_00212f00(state, 1) == 8) {
  offset = 1;
  object = FUN_00213290(state, 1);
 }
 int level = offset + 1;
 int value = FUN_00339f70(state, level);
 if (!FUN_00213fc0(object, value, &ar)) {
  int result = FUN_00339c30(state, level, "level out of range");
  return result;
 }
 level = offset + 3;
 FUN_00339dc0(state, level);
 FUN_00212d80(state, level);
 FUN_00212cb0(state, object, 1);
 value = FUN_00339f70(state, offset + 2);
 const char* result = FUN_002140c0(object, &ar, value);
 FUN_002133d0(state, result);
 return 1;
}


// 0x0033a970 FUN_0033a970 (206 B): equivalent/0x0033a970.cpp
// sym: _FUN_0033a970
// STATUS: equivalent (tools/equiv.py level 3: 2586 inputs, branch coverage 6/6)
// FUN_0033a970 @ 0x0033a970
// db_debug: a line-by-line console until "cont".
extern "C" int __cdecl FUN_0033a970(LuaVMState *state) {
 char line[250];
 FUN_00347eed("lua_debug> ", ((LuaVMFile*)&DAT_004d9a30));
 while (_fgets(line,250,&DAT_004d99f0)) {
  const char *end="cont\n";
  int i;
  for(i=0;i<6;++i) if(line[i]!=end[i]) break;
  if(i==6) break;
  FUN_00339c00(state,line);
  FUN_00212d80(state,0);
  FUN_00347eed("lua_debug> ",((LuaVMFile*)&DAT_004d9a30));
 }
 return 0;
}


// 0x0033aa40 FUN_0033aa40 (574 B): equivalent/0x0033aa40.cpp
// sym: _FUN_0033aa40
// STATUS: equivalent (tools/equiv.py level 3: 2615 inputs, branch coverage 32/32)
// FUN_0033aa40 @ 0x0033aa40
// Lua 5.0 errorfb (stack traceback builder)
extern "C" int __cdecl FUN_0033aa40(LuaVMState* L)
{
    Frame_33aa40 f;
    int level = 1;
    LuaVMState* L1;

    f.firstpart = 1;
    if (FUN_00212f00(L, 1) == 8) {
        f.arg = 1;
        L1 = FUN_00213290(L, 1);
    } else {
        f.arg = 0;
        L1 = L;
    }

    if (FUN_00212d70(L) == f.arg) {
        FUN_00213380(L, "", 0);
    } else {
        if (!FUN_00212fb0(L, f.arg + 1)) {
            return 1;
        }
        FUN_00213380(L, "\n", 1);
    }
    FUN_00213380(L, "stack traceback:", 16);

    while (FUN_00213fc0(L1, level++, &f.ar)) {
        if (level > 12 && f.firstpart) {
            if (!FUN_00213fc0(L1, level + 10, &f.ar)) {
                level--;
            } else {
                FUN_00213380(L, "\n\t...", 5);
                while (FUN_00213fc0(L1, level + 10, &f.ar))
                    level++;
            }
            f.firstpart = 0;
            continue;
        }
        FUN_00213380(L, "\n\t", 2);
        FUN_00214bd0(L1, "Snl", &f.ar);
        FUN_00213470(L, "%s:", f.ar.short_src);
        if (f.ar.currentline > 0)
            FUN_00213470(L, "%d:", f.ar.currentline);
        switch (*f.ar.namewhat) {
        case 'f':
        case 'g':
        case 'l':
        case 'm':
            FUN_00213470(L, " in function `%s'", f.ar.name);
            break;
        default:
            if (*f.ar.what == 'm')
                FUN_00213470(L, " in main chunk");
            else if (*f.ar.what == 'C' || *f.ar.what == 't')
                FUN_00213380(L, " ?", 2);
            else
                FUN_00213470(L, " in function <%s:%d>", f.ar.short_src, f.ar.linedefined);
            break;
        }
        FUN_00213c90(L, FUN_00212d70(L) - f.arg);
    }
    FUN_00213c90(L, FUN_00212d70(L) - f.arg);
    return 1;
}

} // namespace fn_f85c1dd7

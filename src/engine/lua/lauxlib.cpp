// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00338d90..0x0033a080 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/core.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f1b96001 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1b96001 {} using namespace fn_f1b96001;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f1b96001 {
extern "C" void __cdecl FUN_00338d90(LuaVMState* L, int level);
extern "C" const char* __cdecl FUN_00213440(LuaVMState* L, const char* fmt, char* argp);
extern "C" void __cdecl FUN_00213c90(LuaVMState* L, int n);
extern "C" int __cdecl FUN_00213c40(LuaVMState* L);
extern "C" void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213680(LuaVMState* L, int narray, int nrec);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212c50(LuaVMState* L, int size);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_002136d0(LuaVMState* L, int objindex);
extern "C" void __cdecl FUN_00212de0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" int __cdecl FUN_00339010(LuaVMState* L, int obj, const char* event);
extern "C" void __cdecl FUN_002139a0(LuaVMState* L, int nargs, int nresults);
extern "C" {
void __cdecl FUN_00212e20(LuaVMState*, int);
}
extern "C" {
void __cdecl FUN_002134a0(LuaVMState*, LuaVMCFunction, int);
}
extern "C" void __cdecl FUN_00213640(LuaVMState *L, int index, int n);
extern "C" int __cdecl FUN_002138e0(LuaVMState *L, int index);
extern "C" void __cdecl FUN_00213380(LuaVMState *L, const char *s, unsigned int len);
extern "C" void __cdecl FUN_00213870(LuaVMState *L, int index, int n);
extern "C" void __cdecl FUN_003391f0(LuaVMState*);
extern "C" void __cdecl FUN_00213360(LuaVMState*, int);
extern "C" void __cdecl FUN_00213600(LuaVMState*,int);
extern "C" int __cdecl FUN_00213120(LuaVMState*,int);
extern "C++" __declspec(nothrow) void __cdecl FUN_003393f0(LuaVMLBuffer* B);
extern "C" unsigned int __cdecl FUN_002131f0(LuaVMState *L, int idx);
extern "C" const char *__cdecl FUN_00213190(LuaVMState *L, int idx);
extern "C" {
int __cdecl FUN_003392c0(LuaVMState* L, int a);
}
extern "C" {
void __cdecl FUN_00339270(LuaVMState* L, int a, int b);
}
extern "C" unsigned int __cdecl fread(void*, unsigned int, unsigned int, LuaVMFile*);
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" const char* __cdecl FUN_00339a40(LuaVMState* L, void* ud, unsigned int* size);
extern "C" int __cdecl FUN_00213b20(LuaVMState* L, LuaVMReader reader, void* data, const char* chunkname);
extern "C" void FUN_003479bc(void*);
extern "C" void* FUN_00347d7a(void*, unsigned int);
extern "C" void* __cdecl FUN_00339a90(void* ud, void* ptr, unsigned int osize, unsigned int nsize);
extern "C" LuaVMState* __cdecl FUN_002150e0(LuaVMAlloc f, void* ud);
extern "C" const char DAT_00428328[];
extern "C" int __cdecl FID_conflict__fwprintf(void *stream, const char *format, const char *text);
extern "C" int __cdecl FUN_002139f0(LuaVMState* L, int nargs, int nresults, int errfunc);
extern "C" void __cdecl FUN_00339ad0(int status, LuaVMState* L);
extern "C" int __cdecl FUN_00339ba0(LuaVMState* L, const char* buff, unsigned int size, const char* name);
extern "C" const char* __cdecl FUN_00212f20(LuaVMState* L, int t);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" float __cdecl FUN_002130e0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212f70(LuaVMState* L, int idx);
extern "C" float __cdecl FUN_00339ec0(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int narg);


// 0x00338e20 FUN_00338e20 (48 B): matches/0x00338e20.cpp
// sym: _FUN_00338e20
// luaL_error: "where" + the formatted message, then lua_error.
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...) {
    FUN_00338d90(L, 1);
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, fmt);
    FUN_00213440(L, fmt, (char*)args);
#else
    FUN_00213440(L, fmt, (char*)&fmt + sizeof(fmt));
#endif
    FUN_00213c90(L, 2);
    return FUN_00213c40(L);
}


// 0x00338e50 FUN_00338e50 (92 B): matches/0x00338e50.cpp
// sym: _FUN_00338e50
// luaL_findstring: the index of name in a null-ended list, or -1.
extern "C" int __cdecl FUN_00338e50(const char* name, const char* const* list) {
    int i = 0;
    const char* p = list[0];
    while (p) {
        if (strcmp(p, name) == 0)
            return i;
        p = list[++i];
    }
    return -1;
}


// 0x00338eb0 FUN_00338eb0 (117 B): matches/0x00338eb0.cpp
// sym: _FUN_00338eb0
// luaL_newmetatable: registry[tname] = a new table (and registry[table] = tname); 0 when it exists.
extern "C" int __cdecl FUN_00338eb0(LuaVMState* L, const char* tname) {
    FUN_002135a0(L, -10000, tname);
    if (FUN_00212f00(L, -1))
        return 0;
    FUN_00212d80(L, -2);
    FUN_00213680(L, 0, 0);
    FUN_00212ed0(L, -1);
    FUN_00213790(L, -10000, tname);
    FUN_00212ed0(L, -1);
    FUN_002133d0(L, tname);
    FUN_00213800(L, -10000);
    return 1;
}


// 0x00338f30 FUN_00338f30 (24 B): matches/0x00338f30.cpp
// sym: _FUN_00338f30
// luaL_getmetatable: registry[tname].
extern "C" void __cdecl FUN_00338f30(LuaVMState* L, const char* tname) {
    FUN_002135a0(L, -10000, tname);
}


// 0x00338fe0 FUN_00338fe0 (44 B): matches/0x00338fe0.cpp
// sym: _FUN_00338fe0
// luaL_checkstack
extern "C" void __cdecl FUN_00338fe0(LuaVMState* L, int space, const char* mes) {
    if (!FUN_00212c50(L, space))
        FUN_00338e20(L, "stack overflow (%s)", mes);
}


// 0x00339010 FUN_00339010 (84 B): matches/0x00339010.cpp
// sym: _FUN_00339010
// luaL_getmetafield: pushes the metatable's field event of obj; 0 (nothing pushed) when absent.
extern "C" int __cdecl FUN_00339010(LuaVMState* L, int obj, const char* event) {
    if (!FUN_002136d0(L, obj))
        return 0;
    FUN_002135a0(L, -1, event);
    if (!FUN_00212f00(L, -1)) {
        FUN_00212d80(L, -3);
        return 0;
    }
    FUN_00212de0(L, -2);
    return 1;
}


// 0x00339070 FUN_00339070 (85 B): matches/0x00339070.cpp
// sym: _FUN_00339070
// luaL_callmeta
extern "C" int FUN_00339070(LuaVMState* L, int obj, const char* event) {
    if (obj <= 0 && obj > -10000)
        obj = obj + 1 + FUN_00212d70(L);
    if (FUN_00339010(L, obj, event) == 0)
        return 0;
    FUN_00212ed0(L, obj);
    FUN_002139a0(L, 1, 1);
    return 1;
}


// 0x003390d0 FUN_003390d0 (223 B): matches/0x003390d0.cpp
// sym: _FUN_003390d0
// luaL_openlib
extern "C" void __cdecl FUN_003390d0(LuaVMState* state, const char* name, const LuaVMReg* entries, int upvalueCount) {
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
            FUN_002134a0(state, entries->func, upvalueCount);
            FUN_00213790(state, destination, entries->name);
            ++entries;
        } while (entries->name);
    }
    FUN_00212d80(state, -1 - upvalueCount);
}


// 0x003391f0 FUN_003391f0 (116 B): equivalent/0x003391f0.cpp
// sym: _FUN_003391f0 @b43cef487b20 @w1de259553b98
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_003391f0 @ 0x003391f0
// getsizes: pushes registry[2], the weak-keyed table of explicit table sizes (created on first use).
// equiv-conv: FUN_003391f0 esi
extern "C" void __cdecl FUN_003391f0(LuaVMState *L)
{
    FUN_00213640(L, -10000, 2);
    if (FUN_00212f00(L, -1) == 0) {
        FUN_00212d80(L, -2);
        FUN_00213680(L, 0, 0);
        FUN_00212ed0(L, -1);
        FUN_002138e0(L, -2);
        FUN_00213380(L, "kv", 2);
        FUN_00213790(L, -2, "__mode");
        FUN_00212ed0(L, -1);
        FUN_00213870(L, -10000, 2);
    }
}


// 0x00339270 FUN_00339270 (80 B): equivalent/0x00339270.cpp
// sym: _FUN_00339270 @8d997c45ecc2 @w54a8557823d7
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_00339270 @ 0x00339270
// luaL_setn
// equiv-conv: FUN_003391f0 esi
extern "C" void __cdecl FUN_00339270(LuaVMState* a, int b, int c) {
    if (b <= 0 && b > -10000)
        b = b + 1 + FUN_00212d70(a);
    FUN_003391f0(a);
    FUN_00212ed0(a, b);
    FUN_00213360(a, c);
    FUN_00213800(a, -3);
    FUN_00212d80(a, -2);
}


// 0x003392c0 FUN_003392c0 (250 B): equivalent/0x003392c0.cpp
// sym: _FUN_003392c0 @b77417cfe9f2 @wc2cf73e536c4
// STATUS: equivalent (tools/equiv.py level 3: 2575 inputs, branch coverage 16/16)
// FUN_003392c0 @ 0x003392c0
// luaL_getn
// equiv-conv: FUN_003391f0 esi
extern "C" int __cdecl FUN_003392c0(LuaVMState* state,int index) {
 if(index<=0 && index>-10000) index=index+FUN_00212d70(state)+1;
 FUN_003391f0(state);
 FUN_00212ed0(state,index);
 FUN_00213600(state,-2);
 int length=-1;
 if(FUN_00212f00(state,-1)==3) length=FUN_00213120(state,-1);
 FUN_00212d80(state,-3);
 if(length>=0) return length;
 FUN_002135a0(state,index,((const char*)&DAT_00426788));
 length=-1;
 if(FUN_00212f00(state,-1)==3) length=FUN_00213120(state,-1);
 FUN_00212d80(state,-2);
 if(length>=0) return length;
 int count=1;
 FUN_00213640(state,index,count);
 while(FUN_00212f00(state,-1)!=0) {
 FUN_00212d80(state,-2);
 ++count;
 FUN_00213640(state,index,count);
 }
 FUN_00212d80(state,-2);
 return count-1;
}

} // namespace fn_f1b96001

// 0x003393f0 FUN_003393f0 (123 B): matches/0x003393f0.cpp [wrapped: macros]
// sym: _FUN_003393f0
namespace fn_003393f0 {
// FUN_003393f0 @ 0x003393f0
// Lua 5.0 lauxlib adjuststack: concatenates the buffer's pending strings on the stack.

extern "C++" __declspec(nothrow) unsigned int __cdecl FUN_002131f0(LuaVMState* L, int idx);   // lua_strlen
extern "C++" __declspec(nothrow) void __cdecl FUN_00213c90(LuaVMState* L, int n);             // lua_concat

#define LIMIT 10

extern "C" void __cdecl FUN_003393f0(LuaVMLBuffer* B) {
    if (B->lvl > 1) {
        LuaVMState* L = B->L;
        int toget = 1;
        unsigned int toplen = FUN_002131f0(L, -1);
        do {
            unsigned int l = FUN_002131f0(L, -(toget + 1));
            if (B->lvl - toget + 1 >= LIMIT || toplen > l) {
                toplen += l;
                toget++;
            } else {
                break;
            }
        } while (toget < B->lvl);
        FUN_00213c90(L, toget);
        B->lvl = B->lvl - toget + 1;
    }
}
} // namespace fn_003393f0
#undef LIMIT

namespace fn_f1b96001 {

// 0x00339470 FUN_00339470 (53 B): matches/0x00339470.cpp
// sym: _FUN_00339470
// luaL_prepbuffer: empties the buffer onto the stack and returns its start.
extern "C" char* __cdecl FUN_00339470(LuaVMLBuffer* B) {
    unsigned int n = (unsigned int)(B->p - B->buffer);
    if (n != 0) {
        FUN_00213380(B->L, B->buffer, n);
        B->p = B->buffer;
        ++B->lvl;
        FUN_003393f0(B);
    }
    return B->buffer;
}


// 0x003394b0 FUN_003394b0 (93 B): matches/0x003394b0.cpp
// sym: _FUN_003394b0
// luaL_addlstring
extern "C" void __cdecl FUN_003394b0(LuaVMLBuffer* b, const char* src, unsigned int n) {
    for (; n != 0; --n) {
        if (b->p >= b->buffer + LUAVM_BUFFERSIZE) {
            unsigned int len = (unsigned int)(b->p - b->buffer);
            if (len != 0) {
                FUN_00213380(b->L, b->buffer, len);
                b->p = b->buffer;
                ++b->lvl;
                FUN_003393f0(b);
            }
        }
        *b->p++ = *src++;
    }
}


// 0x00339540 FUN_00339540 (67 B): matches/0x00339540.cpp
// sym: _FUN_00339540
// luaL_pushresult
extern "C" void __cdecl FUN_00339540(LuaVMLBuffer* p) {
    unsigned int diff = (unsigned int)(p->p - p->buffer);
    if (diff != 0) {
        char* dst = p->buffer;
        FUN_00213380(p->L, dst, diff);
        p->p = dst;
        p->lvl = p->lvl + 1;
    }
    FUN_00213c90(p->L, p->lvl);
    p->lvl = 1;
}


// 0x00339590 FUN_00339590 (159 B): matches/0x00339590.cpp
// sym: _FUN_00339590
// FUN_00339590 @ 0x00339590
// FUN_00339590: Lua 5.0 lauxlib luaL_addvalue
                              // adjuststack
extern "C" void __cdecl FUN_00339590(LuaVMLBuffer *B)
{
    LuaVMState *L = B->L;
    unsigned int vl = FUN_002131f0(L, -1);
    if (vl <= (unsigned int)(&B->buffer[LUAVM_BUFFERSIZE] - B->p)) {
        memcpy(B->p, FUN_00213190(L, -1), vl);
        B->p += vl;
        FUN_00212d80(L, -2);
    } else {
        unsigned int len = (unsigned int)(B->p - B->buffer);
        if (len != 0) {
            FUN_00213380(B->L, B->buffer, len);
            B->p = B->buffer;
            B->lvl++;
            FUN_00212e20(L, -2);
        }
        B->lvl++;
        FUN_003393f0(B);
    }
}


// 0x00339630 FUN_00339630 (24 B): matches/0x00339630.cpp
// sym: _FUN_00339630
// luaL_buffinit
extern "C" void __cdecl FUN_00339630(LuaVMState* L, LuaVMLBuffer* buffer) {
    buffer->L = L;
    buffer->p = buffer->buffer;
    buffer->lvl = 0;
}


// 0x00339650 FUN_00339650 (190 B): matches/0x00339650.cpp
// sym: _FUN_00339650
// luaL_ref
extern "C" int __cdecl FUN_00339650(LuaVMState* L, int idx) {
    if (idx <= 0 && idx > -10000) {
        idx = idx + FUN_00212d70(L) + 1;
    }
    if (!FUN_00212f00(L, -1)) {
        FUN_00212d80(L, -2);
        return -1;
    }
    FUN_00213640(L, idx, 1);
    int r = FUN_00213120(L, -1);
    FUN_00212d80(L, -2);
    if (r) {
        FUN_00213640(L, idx, r);
        FUN_00213870(L, idx, 1);
    } else {
        r = FUN_003392c0(L, idx);
        if (r < 2)
            r = 2;
        r++;
        FUN_00339270(L, idx, r);
    }
    FUN_00213870(L, idx, r);
    return r;
}


// 0x00339710 FUN_00339710 (84 B): matches/0x00339710.cpp
// sym: _FUN_00339710
// luaL_unref
extern "C" void __cdecl FUN_00339710(LuaVMState* L, int index, int n) {
    if (n >= 0) {
        if (index <= 0 && index > -10000)
            index = index + 1 + FUN_00212d70(L);
        FUN_00213640(L, index, 1);
        FUN_00213870(L, index, n);
        FUN_00213360(L, n);
        FUN_00213870(L, index, 1);
    }
}


// 0x00339770 FUN_00339770 (80 B): matches/0x00339770.cpp
// sym: _FUN_00339770
// getF: luaL_loadfile's reader (a LuaVMReader; ud is the LuaVMLoadF).
// data: marker = DAT_00422518
extern "C" const char* __cdecl FUN_00339770(LuaVMState* L, void* ud, unsigned int* count) {
    LuaVMLoadF* b = (LuaVMLoadF*)ud;
    if (b->extraline) {
        b->extraline = 0;
        *count = 1;
        return ((const char*)&DAT_00422518);
    }
    LuaVMFile* f = b->f;
    if (f->flag & 16)
        return 0;
    unsigned int n = fread(b->buff, 1, LUAVM_BUFFERSIZE, f);
    *count = n;
    return n > 0 ? b->buff : 0;
}


// 0x003397c0 FUN_003397c0 (54 B): equivalent/0x003397c0.cpp
// sym: _FUN_003397c0 @817810d4233a @w4b1e99a30086
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// FUN_003397c0 @ 0x003397c0
// errfile: "cannot read <file name>: <strerror(errno)>" in place of the chunk name.
// equiv-conv: FUN_003397c0 edi ebx
extern "C" int __cdecl FUN_003397c0(LuaVMState* L, int fnameindex)
{
    const char* filename = FUN_00213190(L, fnameindex) + 1;
    int code = *FUN_00347ba4();
    const char* description = FUN_00347b53(code);
    FUN_00213470(L, "cannot read %s: %s", filename, description);
    FUN_00212de0(L, fnameindex);
    return 2;
}


// 0x00339a40 FUN_00339a40 (30 B): matches/0x00339a40.cpp
// sym: _FUN_00339a40
// getS: luaL_loadbuffer's reader (a LuaVMReader; ud is the LuaVMLoadS): the whole buffer once.
extern "C" const char* __cdecl FUN_00339a40(LuaVMState* L, void* ud, unsigned int* out) {
    LuaVMLoadS* p = (LuaVMLoadS*)ud;
    unsigned int b = p->size;
    if (!b)
        return 0;
    *out = b;
    p->size = 0;
    return p->s;
}


// 0x00339a60 FUN_00339a60 (48 B): matches/0x00339a60.cpp
// sym: _FUN_00339a60
// luaL_loadbuffer
extern "C" int __cdecl FUN_00339a60(LuaVMState* L, const char* buff, unsigned int size, const char* name) {
    LuaVMLoadS ls;
    ls.s = buff;
    ls.size = size;
    return FUN_00213b20(L, FUN_00339a40, &ls, name);
}


// 0x00339a90 FUN_00339a90 (39 B): matches/0x00339a90.cpp
// sym: _FUN_00339a90
// l_alloc: luaL_newstate's allocator (a LuaVMAlloc): free on a zero size, else realloc.
   // realloc
extern "C" void* __cdecl FUN_00339a90(void* ud, void* p, unsigned int osize, unsigned int nsize) {
    if (!nsize) {
        FUN_003479bc(p);
        return 0;
    }
    return FUN_00347d7a(p, nsize);
}


// 0x00339ac0 FUN_00339ac0 (16 B): matches/0x00339ac0.cpp
// sym: _FUN_00339ac0
// luaL_newstate
extern "C" LuaVMState* __cdecl FUN_00339ac0(void) {
    return FUN_002150e0(FUN_00339a90, 0);
}


// 0x00339ad0 FUN_00339ad0 (91 B): equivalent/0x00339ad0.cpp
// sym: _FUN_00339ad0 @887fb5f3a049 @w974c8d82c42b
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_00339ad0 @ 0x00339ad0
// aux_do's error report: a failed chunk's message goes to the global ALERT function, or to stderr.
// equiv-conv: FUN_00339ad0 eax esi
extern "C" void __cdecl FUN_00339ad0(int active, LuaVMState *session)
{
    if (!active) return;
    FUN_002135a0(session, -10001, DAT_0043469c);
    int result = FUN_00212f00(session, -1);
    if (result == 6) {
        FUN_00212e20(session, -2);
        FUN_002139a0(session, 1, 0);
    } else {
        const char *message = FUN_00213190(session, -2);
        FID_conflict__fwprintf(((void*)&DAT_004d9a30), DAT_00428328, message);
        FUN_00212d80(session, -3);
    }
}


// 0x00339ba0 FUN_00339ba0 (85 B): equivalent/0x00339ba0.cpp
// sym: _FUN_00339ba0 @324cf01e1e4b @w755eef53cebc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00339ba0 @ 0x00339ba0
// lua_dobuffer
// equiv-conv: FUN_00339ad0 eax esi
extern "C" int __cdecl FUN_00339ba0(LuaVMState* source, const char* first, unsigned int second, const char* last)
{
    LuaVMLoadS data;
    data.s = first;
    data.size = second;
    int result = FUN_00213b20(source, FUN_00339a40, &data, last);
    if (result == 0)
        result = FUN_002139f0(source, 0, -1, 0);
    FUN_00339ad0(result, source);
    return result;
}


// 0x00339c00 FUN_00339c00 (43 B): matches/0x00339c00.cpp
// sym: _FUN_00339c00
// lua_dostring
extern "C" int __cdecl FUN_00339c00(LuaVMState* p, const char* s) {
    return FUN_00339ba0(p, s, strlen(s), s);
}


// 0x00339cf0 FUN_00339cf0 (55 B): matches/0x00339cf0.cpp
// sym: _FUN_00339cf0
// luaL_typerror
// data: fmt = DAT_004346e4
extern "C" int __cdecl FUN_00339cf0(LuaVMState* x, int y, const char* z) {
    return FUN_00339c30(x, y, FUN_00213470(x, DAT_004346e4, z, FUN_00212f20(x, FUN_00212f00(x, y))));
}


// 0x00339d70 FUN_00339d70 (80 B): matches/0x00339d70.cpp
// sym: _FUN_00339d70
// luaL_checktype
extern "C" void __cdecl FUN_00339d70(LuaVMState* a, int b, int c) {
    int x = FUN_00212f00(a, b);
    if (x != c) {
        const char* y = FUN_00212f20(a, c);
        int t = FUN_00212f00(a, b);
        const char* z = FUN_00212f20(a, t);
        z = FUN_00213470(a, "%s expected, got %s", y, z);
        FUN_00339c30(a, b, z);
    }
}


// 0x00339dc0 FUN_00339dc0 (43 B): matches/0x00339dc0.cpp
// sym: _FUN_00339dc0
// luaL_checkany
extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int index) {
    if (FUN_00212f00(L, index) == -1)
        FUN_00339c30(L, index, "value expected");
}


// 0x00339df0 FUN_00339df0 (104 B): matches/0x00339df0.cpp
// sym: _FUN_00339df0
// luaL_checklstring
extern "C" const char* __cdecl FUN_00339df0(LuaVMState* a, int b, unsigned int* out) {
    const char* r = FUN_00213190(a, b);
    if (!r) {
        const char* x = FUN_00212f20(a, 4);
        const char* y = FUN_00212f20(a, FUN_00212f00(a, b));
        FUN_00339c30(a, b, FUN_00213470(a, "%s expected, got %s", x, y));
    }
    if (out)
        *out = FUN_002131f0(a, b);
    return r;
}


// 0x00339e60 FUN_00339e60 (87 B): equivalent/0x00339e60.cpp
// sym: _FUN_00339e60 @a5fc578969ec @wbcfebfd609a1
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 8/8)
// FUN_00339e60 @ 0x00339e60
// luaL_optlstring
extern "C" const char* __cdecl FUN_00339e60(LuaVMState* a, int b, const char* text, unsigned int* length)
{
    if (FUN_00212f00(a, b) > 0)
        return FUN_00339df0(a, b, length);
    if (length) {
        if (text) {
            const char* p = text;
            while (*p) ++p;
            *length = (unsigned int)(p - text);
        } else {
            *length = 0;
        }
    }
    return text;
}


// 0x00339ec0 FUN_00339ec0 (116 B): matches/0x00339ec0.cpp
// sym: _FUN_00339ec0
// luaL_checknumber
// data: Zero_339ec0 = DAT_003f32e0
extern "C" float __cdecl FUN_00339ec0(LuaVMState* a, int b) {
    float f = FUN_002130e0(a, b);
    if (f == DAT_003f32e0) {
        if (FUN_00212f70(a, b) == 0) {
            const char* x = FUN_00212f20(a, 3);
            const char* y = FUN_00212f20(a, FUN_00212f00(a, b));
            FUN_00339c30(a, b, FUN_00213470(a, "%s expected, got %s", x, y));
        }
    }
    return f;
}


// 0x00339f40 FUN_00339f40 (44 B): matches/0x00339f40.cpp
// sym: _FUN_00339f40
// luaL_optnumber
extern "C" float __cdecl FUN_00339f40(LuaVMState* L, int index, float fallback) {
    int value = FUN_00212f00(L, index);
    if (value <= 0)
        return fallback;
    return FUN_00339ec0(L, index);
}


// 0x00339f70 FUN_00339f70 (97 B): matches/0x00339f70.cpp
// sym: _FUN_00339f70
// luaL_checkint
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int o) {
    int r = FUN_00213120(L, o);
    if (r == 0) {
        if (FUN_00212f70(L, o) == 0) {
            const char* a = FUN_00212f20(L, 3);
            const char* b = FUN_00212f20(L, FUN_00212f00(L, o));
            FUN_00339c30(L, o, FUN_00213470(L, "%s expected, got %s", a, b));
        }
    }
    return r;
}


// 0x00339fe0 FUN_00339fe0 (44 B): matches/0x00339fe0.cpp
// sym: _FUN_00339fe0
// luaL_optint
extern "C" int __cdecl FUN_00339fe0(LuaVMState* a, int b, int c) {
    int r = FUN_00212f00(a, b);
    if (r <= 0)
        return c;
    return FUN_00339f70(a, b);
}

} // namespace fn_f1b96001

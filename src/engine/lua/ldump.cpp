// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0021a790..0x0021add0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f87cdbec {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f87cdbec {} using namespace fn_f87cdbec;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f87cdbec {
extern "C" void __cdecl FUN_0021ab30(const LuaVMProto* f, const LuaVMString* p, LuaVMDumpState* D);
extern "C" void __cdecl FUN_0021a790(const LuaVMString* s, LuaVMDumpState* D);
extern "C" void __cdecl FUN_0021a830(LuaVMDumpState* D, const LuaVMProto* f);
extern "C" void __cdecl FUN_0021a960(LuaVMDumpState* D, const LuaVMProto* f);
extern "C" void __cdecl FUN_0021aa00(LuaVMDumpState* D, const LuaVMProto* f);
union LuaVMDumpScratch_21ab30 {
    int i;
    unsigned char c;
};
extern "C" char __cdecl FUN_00220300();
extern "C" void __cdecl FUN_0021acc0(LuaVMDumpState* D);


// 0x0021a790 FUN_0021a790 (89 B): equivalent/0x0021a790.cpp
// sym: _FUN_0021a790 @a685b12e96c0 @w21d755854d71
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 3/3)
// DumpString: a string as its size (with the NUL; 0 for none) and its characters.
// equiv-conv: FUN_0021a790 eax esi
extern "C" void __cdecl FUN_0021a790(const LuaVMString* s, LuaVMDumpState* D) {
    unsigned int size = 0;  // the chunk's size_t: 4 bytes
    if (s && LUAVM_GETSTR(s)) {
        const unsigned int len = s->len + 1;
        size = len;
        D->writer(D->L, &size, 4, D->data);
        D->writer(D->L, LUAVM_GETSTR(s), len, D->data);
    } else {
        unsigned int* volatile address = &size;
        D->writer(D->L, address, 4, D->data);
    }
}


// 0x0021a830 FUN_0021a830 (230 B): equivalent/0x0021a830.cpp
// sym: _FUN_0021a830 @f65c87a4ec83 @wdce00ea3da26
// STATUS: equivalent (tools/equiv.py level 3: 576 inputs, branch coverage 7/7)
// DumpLocals: the local variables' count, then each one's name, startpc and endpc.
// equiv-conv: FUN_0021a830 esi stack
extern "C" void __cdecl FUN_0021a830(LuaVMDumpState* D, const LuaVMProto* f) {
    const int n = f->sizelocvars;
    int x = n;
    struct {
        int len;
        union {
            const char* str;
            int value;
        };
    } scratch;  // the original's slots: a string's size next to its characters' address, the integers in the second
    D->writer(D->L, &x, 4, D->data);
    if (n <= 0)
        return;
    int remaining = n;
    for (int i = 0; remaining; ++i, --remaining) {
        const LuaVMString* s = f->locvars[i].varname;
        if (s && LUAVM_GETSTR(s)) {
            scratch.str = LUAVM_GETSTR(s);
            const int len = s->len + 1;
            scratch.len = len;
            D->writer(D->L, &scratch.len, 4, D->data);
            D->writer(D->L, scratch.str, len, D->data);
        } else {
            scratch.value = 0;
            D->writer(D->L, &scratch.value, 4, D->data);
        }
        scratch.value = f->locvars[i].startpc;
        D->writer(D->L, &scratch.value, 4, D->data);
        scratch.value = f->locvars[i].endpc;
        D->writer(D->L, &scratch.value, 4, D->data);
    }
}


// 0x0021a960 FUN_0021a960 (155 B): equivalent/0x0021a960.cpp
// sym: _FUN_0021a960 @5773cba2e42e @wb358bb7bdc35
// STATUS: equivalent (tools/equiv.py level 3: 1321 inputs, branch coverage 7/7)
// DumpUpvalues: the upvalue names' count, then each name.
// equiv-conv: FUN_0021a960 esi stack
extern "C" void __cdecl FUN_0021a960(LuaVMDumpState* D, const LuaVMProto* f) {
    int n = f->sizeupvalues;
    int x = n;
    D->writer(D->L, &x, 4, D->data);
    for (int i = 0; i < n; i++) {
        const LuaVMString* s = f->upvalues[i];
        if (s != 0) {
            int len = s->len + 1;
            x = len;
            D->writer(D->L, &x, 4, D->data);
            D->writer(D->L, LUAVM_GETSTR(s), len, D->data);
        } else {
            x = 0;
            D->writer(D->L, &x, 4, D->data);
        }
    }
}


// 0x0021aa00 FUN_0021aa00 (291 B): equivalent/0x0021aa00.cpp
// sym: _FUN_0021aa00 @ee0ddb44dd46 @wb25c8012feeb
// STATUS: equivalent (tools/equiv.py level 3: 644 inputs, branch coverage 15/15)
// DumpConstants: the constants (a type byte, then a number's 4 bytes or a string) and the nested functions.
// equiv-conv: FUN_0021aa00 esi stack
extern "C" void __cdecl FUN_0021aa00(LuaVMDumpState* D, const LuaVMProto* f) {
    int n = f->sizek;
    int x = n;  // one scratch slot for every value written (a type byte goes out with stale upper bytes)
    D->writer(D->L, &x, 4, D->data);
    for (int i = 0; i < n; ++i) {
        const LuaVMTObject* o = &f->k[i];
        x = (x & ~255) | (o->tt & 255);
        D->writer(D->L, &x, 1, D->data);
        if (o->tt == LUAVM_TNUMBER) {
            int bits = o->value.b;  // the number's 4 bytes
            D->writer(D->L, &bits, 4, D->data);
        } else if (o->tt == LUAVM_TSTRING) {
            const LuaVMString* s = (const LuaVMString*)o->value.gc;
            if (s && LUAVM_GETSTR(s)) {
                const char* str = LUAVM_GETSTR(s);
                int len = s->len + 1;
                x = len;
                D->writer(D->L, &x, 4, D->data);
                D->writer(D->L, str, len, D->data);
            } else {
                x = 0;
                D->writer(D->L, &x, 4, D->data);
            }
        }
    }
    int np = f->sizep;
    x = np;
    D->writer(D->L, &x, 4, D->data);
    for (int j = 0; j < np; ++j)
        FUN_0021ab30(f->p[j], f->source, D);
}


// 0x0021ab30 FUN_0021ab30 (392 B): equivalent/0x0021ab30.cpp
// sym: _FUN_0021ab30 @d9503729561e @w265ff9b5089c
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 8/8)
// DumpFunction: a prototype (its source unless the parent's, header bytes, lines, locals, upvalue names (none when
// stripped), constants and code).
// equiv-conv: FUN_0021a790 eax esi
// equiv-conv: FUN_0021a830 esi stack
// equiv-conv: FUN_0021a960 esi stack
// equiv-conv: FUN_0021aa00 esi stack
extern "C" void __cdecl FUN_0021ab30(const LuaVMProto* f, const LuaVMString* p, LuaVMDumpState* D) {
    LuaVMDumpScratch_21ab30 v;
    FUN_0021a790(f->source == p ? 0 : f->source, D);
    v.i = f->lineDefined;
    D->writer(D->L, &v, 4, D->data);
    v.c = f->nups;
    D->writer(D->L, &v, 1, D->data);
    v.c = f->numparams;
    D->writer(D->L, &v, 1, D->data);
    v.c = f->is_vararg;
    D->writer(D->L, &v, 1, D->data);
    v.c = f->maxstacksize;
    D->writer(D->L, &v, 1, D->data);
    if (D->strip) {
        v.i = 0;
        D->writer(D->L, &v, 4, D->data);
    } else {
        v.i = f->sizelineinfo;
        D->writer(D->L, &v, 4, D->data);
        D->writer(D->L, f->lineinfo, f->sizelineinfo * 4, D->data);
    }
    if (D->strip) {
        v.i = 0;
        D->writer(D->L, &v, 4, D->data);
    } else {
        FUN_0021a830(D, f);
    }
    if (D->strip) {
        v.i = 0;
        D->writer(D->L, &v, 4, D->data);
    } else {
        FUN_0021a960(D, f);
    }
    FUN_0021aa00(D, f);
    v.i = f->sizecode;
    D->writer(D->L, &v, 4, D->data);
    D->writer(D->L, f->code, f->sizecode * 4, D->data);
}


// 0x0021acc0 FUN_0021acc0 (192 B): equivalent/0x0021acc0.cpp
// sym: _FUN_0021acc0 @c5e020053093 @waea6742dc6fc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// DumpHeader: the chunk header (signature, version, byte order, the 32-bit sizes, the test number).
// equiv-conv: FUN_0021acc0 esi
extern "C" void __cdecl FUN_0021acc0(LuaVMDumpState* D) {
    struct {
        char pad[3];
        char byte;
        float number;
    } fr;
    D->writer(D->L, "\x1b"
                    "Lua",
              4, D->data);
    fr.byte = 0x51;  // format version
    D->writer(D->L, &fr.byte, 1, D->data);
    fr.byte = FUN_00220300();  // endianness
    D->writer(D->L, &fr.byte, 1, D->data);
    fr.byte = 4;  // sizeof(int) in the chunk
    D->writer(D->L, &fr.byte, 1, D->data);
    fr.byte = 4;  // sizeof(size_t)
    D->writer(D->L, &fr.byte, 1, D->data);
    fr.byte = 4;  // sizeof(Instruction)
    D->writer(D->L, &fr.byte, 1, D->data);
    fr.byte = 4;  // sizeof(lua_Number)
    D->writer(D->L, &fr.byte, 1, D->data);
    fr.number = 31415926.0f;  // test number
    D->writer(D->L, &fr.number, 4, D->data);
}


// 0x0021ad80 FUN_0021ad80 (72 B): equivalent/0x0021ad80.cpp
// sym: _FUN_0021ad80 @3c74f1583033 @w85e06bec0fde
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// luaU_dump: dump a function as a precompiled chunk through w.
// equiv-conv: FUN_0021acc0 esi
extern "C" int __cdecl FUN_0021ad80(LuaVMState* L, const LuaVMProto* f, LuaVMWriter w, void* data, int strip) {
    LuaVMDumpState D;
    D.L = L;
    D.writer = w;
    D.data = data;
    D.strip = strip;
    FUN_0021acc0(&D);
    FUN_0021ab30(f, 0, &D);
    return 1;
}

} // namespace fn_f87cdbec

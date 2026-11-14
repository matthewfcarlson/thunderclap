// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0021f800..0x002204e0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f816444d {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f816444d {} using namespace fn_f816444d;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f816444d {
extern "C" const char* __cdecl FUN_002160c0(LuaVMState* L, const char* fmt, char* argp);
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_002152b0(LuaVMState* L, int errcode);
extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
extern "C" unsigned int __cdecl FUN_0021a610(LuaVMZio* z, void* b, unsigned int n);
extern "C" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);
extern "C" void __cdecl FUN_0021f8c0(char* b, unsigned int size, LuaVMLoadState* S);
extern "C" char* __cdecl FUN_0021a6b0(LuaVMState* L, LuaVMBuffer* buff, unsigned int n);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_0021f940(unsigned int n, unsigned char* b, LuaVMLoadState* S, unsigned int size);
extern "C++" LuaVMProto* __cdecl FUN_00220050(LuaVMLoadState* S, LuaVMString* p);
class pddiObject {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader : public pddiObject {};
class pddiBaseShader : public pddiShader {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader : public pddiBaseShader {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class d3dLayeredShader : public d3dShader {
  public:
    virtual void vfunc3();
    virtual void vfunc4();
    // slots 5-10 inherited
    virtual int UsesLayeredTexture();
    // slots 12-13 inherited from d3dShader
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    // slots 19-20 inherited
    // slot 21 inherited
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
};
extern "C" void __cdecl FUN_00220220(LuaVMLoadState* S);
extern "C" void __cdecl FUN_002202a0(LuaVMLoadState* S, unsigned int expected, const char* what);
extern "C" void __cdecl FUN_00220310(LuaVMLoadState* S);


// 0x0021f800 FUN_0021f800 (50 B): equivalent/0x0021f800.cpp
// sym: _FUN_0021f800 @ef93890ad215 @wae8212b7fa7c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// lundump error: "<chunk name>: <message>" on the stack, then throw LUA_ERRSYNTAX (3).
// C++ linkage on purpose: equiv.py's 32-bit runs pass a wrong first argument to an extern "C" variadic definition
// with a register convention (the callers' extern "C" declarations bind by the address name).
// equiv-conv: FUN_0021f800 esi stack
void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list va;
    __builtin_va_start(va, fmt);
    const char* text = FUN_002160c0(S->L, fmt, va);
#else
    const char* text = FUN_002160c0(S->L, fmt, (char*)(void*)(&fmt + 1));
#endif
    FUN_00216320(S->L, "%s: %s", S->name, text);
    FUN_002152b0(S->L, 3);
}


// 0x0021f8c0 FUN_0021f8c0 (125 B): equivalent/0x0021f8c0.cpp
// sym: _FUN_0021f8c0 @82aeebd749dc @wae7d514e902a
// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 12/12)
// LoadBlock: read size bytes into b, reversed when the chunk's byte order differs.
// equiv-conv: FUN_0021f800 esi stack
// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char* b, unsigned int size, LuaVMLoadState* S) {
    if (S->swap == 0) {
        if (((int)FUN_0021a610(S->Z, b, size)) != 0)
            FUN_0021f800(S, "unexpected end of file");
        return;
    }
    char* dst = b + size - 1;
    for (; size != 0; size--) {
        int c;
        if (S->Z->n-- > 0)
            c = *(const unsigned char*)S->Z->p++;
        else
            c = FUN_0021a550(S->Z);
        if (c == -1)
            FUN_0021f800(S, "unexpected end of file");
        *dst-- = (char)c;
    }
}


// 0x0021f940 FUN_0021f940 (205 B): equivalent/0x0021f940.cpp
// sym: _FUN_0021f940 @7996c9589a05 @w963174c580bf
// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 16/16)
// LoadVector: read n elements of size bytes into b, each reversed when the chunk's byte order differs.
// equiv-conv: FUN_0021f800 esi stack
// equiv-conv: FUN_0021f940 eax ecx edx stack
extern "C" void __cdecl FUN_0021f940(unsigned int n, unsigned char* b, LuaVMLoadState* S, unsigned int size) {
    if (!S->swap) {
        if (((int)FUN_0021a610(S->Z, b, n * size)))
            FUN_0021f800(S, "unexpected end of file");
        return;
    }
    if (!n)
        return;
    unsigned char* end = b + size - 1;
    do {
        unsigned char* out = end;
        unsigned int left = size;
        while (left) {
            LuaVMZio* z = S->Z;
            unsigned int previous = z->n;
            z->n = previous - 1;
            z = S->Z;
            int value;
            if (previous) {
                value = *(const unsigned char*)z->p;
                ++z->p;
            } else {
                value = FUN_0021a550(z);
            }
            if (value == -1)
                FUN_0021f800(S, "unexpected end of file");
            *out-- = (unsigned char)value;
            --left;
        }
        end += size;
    } while (--n);
}


// 0x0021fa80 FUN_0021fa80 (101 B): equivalent/0x0021fa80.cpp
// sym: _FUN_0021fa80 @50c38fd8b6b9 @w148942b3e515
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// LoadString: a size_t length (32 bits in the chunk, counting the NUL), then the characters; 0 is no string.
// equiv-conv: FUN_0021f8c0 ecx eax edx
// equiv-conv: FUN_0021f800 esi stack
// equiv-conv: FUN_0021fa80 eax
extern "C" LuaVMString* __cdecl FUN_0021fa80(LuaVMLoadState* S) {
    unsigned int size;
    FUN_0021f8c0((char*)(void*)(&size), 4, S);
    if (size == 0)
        return 0;
    char* s = FUN_0021a6b0(S->L, S->b, size);
    if (((int)FUN_0021a610(S->Z, s, size)))
        FUN_0021f800(S, "unexpected end of file");
    return FUN_00219430(S->L, s, size - 1);
}


// 0x0021faf0 FUN_0021faf0 (92 B): equivalent/0x0021faf0.cpp
// sym: _FUN_0021faf0 @c75191dbc1e5 @w23e1077190fc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// LoadCode: the instruction count, then the instructions (32 bits each).
// equiv-conv: FUN_0021f8c0 ecx eax edx
// equiv-conv: FUN_0021f800 esi stack
// equiv-conv: FUN_0021f940 eax ecx edx stack
// equiv-conv: FUN_0021faf0 eax ebx
extern "C" void __cdecl FUN_0021faf0(LuaVMLoadState* S, LuaVMProto* f) {
    int size;
    FUN_0021f8c0((char*)(int*)(&size), 4, S);
    if (size < 0)
        FUN_0021f800(S, "bad integer");
    f->code = (LuaVMInstruction*)FUN_0021add0(S->L, 0, 0, size * (unsigned int)sizeof(LuaVMInstruction));
    f->sizecode = size;
    FUN_0021f940((unsigned int)size, (unsigned char*)f->code, S, (unsigned int)sizeof(LuaVMInstruction));
}


// 0x0021fb50 FUN_0021fb50 (348 B): equivalent/0x0021fb50.cpp
// sym: _FUN_0021fb50 @180a817770a6 @wd8c3f00aebd1
// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 17/18, incomplete)
// LoadLocals: the local variable count, then each one's name, startpc and endpc.
// equiv-conv: FUN_0021f8c0 ecx eax edx
// equiv-conv: FUN_0021f800 esi stack
// equiv-conv: FUN_0021fb50 eax stack
extern "C" void __cdecl FUN_0021fb50(LuaVMLoadState* S, LuaVMProto* p) {
    struct {
        int w;
        int count;
        unsigned int size;
        char* s;
        int pad;
        int v;
    } f; // the original's frame: the integers read from the chunk (32 bits each) and the string buffer
    FUN_0021f8c0((char*)(void*)(&f.v), 4, S);
    if (f.v < 0) {
        FUN_0021f800(S, "bad integer");
    }
    int n = f.v;
    p->locvars = (LuaVMLocVar*)FUN_0021add0(S->L, 0, 0, n * (unsigned int)sizeof(LuaVMLocVar));
    p->sizelocvars = n;
    int i;
    for (i = 0; i < n; i++)
        p->locvars[i].varname = 0;
    f.count = n;
    for (i = 0; i < n; i++) {
        FUN_0021f8c0((char*)(void*)(&f.size), 4, S);
        LuaVMString* name = 0;
        if (f.size != 0) {
            f.s = FUN_0021a6b0(S->L, S->b, f.size);
            if (((int)FUN_0021a610(S->Z, f.s, f.size)))
                FUN_0021f800(S, "unexpected end of file");
            name = FUN_00219430(S->L, f.s, f.size - 1);
        }
        p->locvars[i].varname = name;
        FUN_0021f8c0((char*)(void*)(&f.v), 4, S);
        if (f.v < 0)
            FUN_0021f800(S, "bad integer");
        p->locvars[i].startpc = f.v;
        FUN_0021f8c0((char*)(void*)(&f.w), 4, S);
        if (f.w < 0)
            FUN_0021f800(S, "bad integer");
        p->locvars[i].endpc = f.w;
        f.count--; // the original counts the locals left in this frame word (a neighbour of f.w)
    }
}


// 0x0021fcb0 FUN_0021fcb0 (92 B): equivalent/0x0021fcb0.cpp
// sym: _FUN_0021fcb0 @e80f671fbcdf @wc94d61b0d679
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// LoadLines: the line count, then the line of each instruction (32 bits each).
// equiv-conv: FUN_0021f8c0 ecx eax edx
// equiv-conv: FUN_0021f800 esi stack
// equiv-conv: FUN_0021f940 eax ecx edx stack
// equiv-conv: FUN_0021fcb0 eax ebx
extern "C" void __cdecl FUN_0021fcb0(LuaVMLoadState* S, LuaVMProto* f) {
    int size;
    FUN_0021f8c0((char*)(int*)(&size), 4, S);
    if (size < 0)
        FUN_0021f800(S, "bad integer");
    f->lineinfo = (int*)FUN_0021add0(S->L, 0, 0, size * (unsigned int)sizeof(int));
    f->sizelineinfo = size;
    FUN_0021f940((unsigned int)size, (unsigned char*)f->lineinfo, S, (unsigned int)sizeof(int));
}


// 0x0021fd10 FUN_0021fd10 (261 B): equivalent/0x0021fd10.cpp
// sym: _FUN_0021fd10 @e26d9d04f54d @w59b2b5ac53b6
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 18/18)
// LoadUpvalues: the upvalue name count (0 or nups), then each name.
// equiv-conv: FUN_0021f8c0 ecx eax edx
// equiv-conv: FUN_0021f800 esi stack
// equiv-conv: FUN_0021fd10 eax stack
extern "C" void __cdecl FUN_0021fd10(LuaVMLoadState* S, LuaVMProto* f) {
    struct {
        int count;
        int length;
    } local;  // the integers read from the chunk (32 bits each)
    FUN_0021f8c0((char*)(int*)(&local.count), 4, S);
    int count = local.count;
    if (count < 0) {
        FUN_0021f800(S, "bad integer");
        count = local.count;
    }
    if (count != 0 && count != f->nups)
        FUN_0021f800(S, "bad nupvalues (read %d; expected %d)", count, (int)f->nups);
    f->upvalues = (LuaVMString**)FUN_0021add0(S->L, 0, 0, (unsigned int)count * (unsigned int)sizeof(LuaVMString*));
    f->sizeupvalues = count;
    for (int i = 0; i < count; ++i)
        f->upvalues[i] = 0;
    local.count = 0;
    for (int i = 0; i < count; ++i) {
        FUN_0021f8c0((char*)(int*)(&local.length), 4, S);
        int length = local.length;
        LuaVMString* value = 0;
        if (length != 0) {
            char* buffer = FUN_0021a6b0(S->L, S->b, (unsigned int)length);
            if (((int)FUN_0021a610(S->Z, buffer, (unsigned int)length)))
                FUN_0021f800(S, "unexpected end of file");
            value = FUN_00219430(S->L, buffer, (unsigned int)(length - 1));
            i = local.count;
        }
        f->upvalues[i] = value;
        local.count = i + 1;
    }
}


// 0x0021fe20 FUN_0021fe20 (553 B): equivalent/0x0021fe20.cpp
// sym: _FUN_0021fe20 @c3542f93bebe @wa43647f8e247
// STATUS: equivalent (tools/equiv.py level 3: 122 inputs, branch coverage 34/34)
// LoadConstants (nil, number, string constants), then the nested functions.
// equiv-conv: FUN_0021f800 esi stack
// equiv-conv: FUN_0021f8c0 ecx eax edx
// equiv-conv: FUN_0021fe20 eax stack
extern "C" void __cdecl FUN_0021fe20(LuaVMLoadState* S, LuaVMProto* f) {
    struct Frame {
        int n;
        int index;  // constant index, later reused for the function count
        int size;
        int num;    // a number constant's 32 bits
    } fr;           // the integers read from the chunk (32 bits each)

    FUN_0021f8c0((char*)(void*)(&fr.n), 4, S);
    if (fr.n < 0)
        FUN_0021f800(S, "bad integer");

    int n = fr.n;
    f->k = (LuaVMTObject*)FUN_0021add0(S->L, 0, 0, n * (unsigned int)sizeof(LuaVMTObject));
    f->sizek = n;
    for (int i = 0; i < n; ++i)
        f->k[i].tt = LUAVM_TNIL;

    for (fr.index = 0; fr.index < n; ++fr.index) {
        LuaVMTObject* o = &f->k[fr.index];
        LuaVMZio* z = S->Z;
        unsigned int left = z->n;
        z->n = left - 1;
        z = S->Z;
        int c;
        if (left != 0)
            c = *(const unsigned char*)z->p++;
        else
            c = FUN_0021a550(z);
        if (c == -1)
            FUN_0021f800(S, "unexpected end of file");

        switch (c & 0xff) {
        case 0:
            o->tt = LUAVM_TNIL;
            break;
        case 3:
            FUN_0021f8c0((char*)(void*)(&fr.num), 4, S);
            o->value.b = fr.num;  // the lua_Number's bits, copied as the original does (no float load)
            o->tt = LUAVM_TNUMBER;
            break;
        case 4:
            FUN_0021f8c0((char*)(void*)(&fr.size), 4, S);
            if (fr.size == 0) {
                n = fr.n;
                o->value.gc = 0;
                o->tt = LUAVM_TSTRING;
            } else {
                int size = fr.size;
                char* buff = FUN_0021a6b0(S->L, S->b, (unsigned int)size);
                if (((int)FUN_0021a610(S->Z, buff, (unsigned int)size)) != 0)
                    FUN_0021f800(S, "unexpected end of file");
                o->value.gc = (LuaVMGCObject*)FUN_00219430(S->L, buff, (unsigned int)(size - 1));
                n = fr.n;
                o->tt = LUAVM_TSTRING;
            }
            break;
        default:
            FUN_0021f800(S, "bad constant type (%d)", c & 0xff);
            break;
        }
    }

    FUN_0021f8c0((char*)(void*)(&fr.index), 4, S);
    if (fr.index < 0)
        FUN_0021f800(S, "bad integer");

    int np = fr.index;
    f->p = (LuaVMProto**)FUN_0021add0(S->L, 0, 0, np * (unsigned int)sizeof(LuaVMProto*));
    f->sizep = np;
    for (int i = 0; i < np; ++i)
        f->p[i] = 0;
    for (int i = 0; i < np; ++i)
        f->p[i] = FUN_00220050(S, f->source);
}

} // namespace fn_f816444d

// 0x00220050 FUN_00220050 (451 B): equivalent/0x00220050.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: _FUN_00220050 @aa554f052fe5 @w24db8920a7a6
namespace fn_00220050 {
// STATUS: equivalent (tools/equiv.py level 3: 2915 inputs, branch coverage 24/24)
// LoadFunction: a prototype (anchored on the stack while it loads): source, line, sizes, then its parts.

extern "C" LuaVMProto* __cdecl FUN_002196d0(LuaVMState* L);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
// equiv-conv: FUN_0021fa80 eax
extern "C++" LuaVMString* __cdecl FUN_0021fa80(LuaVMLoadState* S);
// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C++" void __cdecl FUN_0021f8c0(char* b, unsigned int size, LuaVMLoadState* S);
// equiv-conv: FUN_0021f800 esi stack
extern "C++" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);
extern "C++" int __cdecl FUN_0021a550(LuaVMZio* z);
// equiv-conv: FUN_0021fcb0 eax ebx
extern "C++" void __cdecl FUN_0021fcb0(LuaVMLoadState* S, LuaVMProto* f);
// equiv-conv: FUN_0021faf0 eax ebx
extern "C++" void __cdecl FUN_0021faf0(LuaVMLoadState* S, LuaVMProto* f);
// equiv-conv: FUN_0021fb50 eax stack
extern "C++" void __cdecl FUN_0021fb50(LuaVMLoadState* S, LuaVMProto* p);
// equiv-conv: FUN_0021fd10 eax stack
extern "C++" void __cdecl FUN_0021fd10(LuaVMLoadState* S, LuaVMProto* f);
// equiv-conv: FUN_0021fe20 eax stack
extern "C++" void __cdecl FUN_0021fe20(LuaVMLoadState* S, LuaVMProto* f);
extern "C" int __cdecl FUN_002146a0(const LuaVMProto* pt);

// LoadByte (inlined in the original).
static int LoadByte(LuaVMLoadState* S) {
    LuaVMZio* z = S->Z;
    unsigned int n = z->n;
    z->n = n - 1;
    z = S->Z;
    int ch;
    if (n != 0) {
        const char* p = z->p;
        ch = *(const unsigned char*)p;
        z->p = p + 1;
    } else {
        ch = FUN_0021a550(z);
    }
    if (ch == -1)
        FUN_0021f800(S, "unexpected end of file");
    return ch;
}

extern "C" LuaVMProto* __cdecl FUN_00220050(LuaVMLoadState* S, LuaVMString* p) {
    int v;
    LuaVMProto* f = FUN_002196d0(S->L);
    LuaVMState* L = S->L;
    LuaVMTObject* t = L->top;
    t->value.gc = (LuaVMGCObject*)f;
    t->tt = LUAVM_TPROTO;
    L = S->L;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    S->L->top++;
    f->source = FUN_0021fa80(S);
    if (f->source == 0)
        f->source = p;
    FUN_0021f8c0((char*)(void*)(&v), 4, S);
    if (v < 0)
        FUN_0021f800(S, "bad integer");
    f->lineDefined = v;
    f->nups = (unsigned char)LoadByte(S);
    f->numparams = (unsigned char)LoadByte(S);
    f->is_vararg = (unsigned char)LoadByte(S);
    f->maxstacksize = (unsigned char)LoadByte(S);
    FUN_0021fcb0(S, f);
    FUN_0021fb50(S, f);
    FUN_0021fd10(S, f);
    FUN_0021fe20(S, f);
    FUN_0021faf0(S, f);
    if (FUN_002146a0(f) == 0)
        FUN_0021f800(S, "bad code");
    S->L->top--;
    return f;
}
} // namespace fn_00220050

namespace fn_f816444d {

// 0x00220220 FUN_00220220 (115 B): equivalent/0x00220220.cpp
// sym: _FUN_00220220 @fe8af202837f @w769c20b79c5f
// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 10/10)
// LoadSignature: the chunk starts with "\x1bLua".
// equiv-conv: FUN_0021f800 esi stack
// equiv-conv: FUN_00220220 eax
extern "C" void __cdecl FUN_00220220(LuaVMLoadState* S) {
    const char* s = "\x1bLua";
    for (;;) {
        int c;
        if (S->Z->n-- > 0)
            c = *(const unsigned char*)S->Z->p++;
        else
            c = FUN_0021a550(S->Z);
        if (c == -1)
            FUN_0021f800(S, "unexpected end of file");
        if (c != *s)
            break;
        s++;
        if (*s == 0)
            return;
    }
    if (*s != 0)
        FUN_0021f800(S, "bad signature");
}


// 0x002202a0 FUN_002202a0 (92 B): equivalent/0x002202a0.cpp
// sym: _FUN_002202a0 @b55a47eafaee @wcc36ee4f2c30
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// TestSize: the chunk's size byte for a type must be the expected one (the chunk format's sizes).
// equiv-conv: FUN_0021f800 esi stack
// equiv-conv: FUN_002202a0 eax edi stack
extern "C" void __cdecl FUN_002202a0(LuaVMLoadState* S, unsigned int expected, const char* what) {
    LuaVMZio* z = S->Z;
    unsigned int count = z->n;
    z->n = count - 1;
    int value;
    if (count == 0) {
        value = FUN_0021a550(S->Z);
    } else {
        const char* cursor = S->Z->p;
        value = *(const unsigned char*)cursor;
        S->Z->p = cursor + 1;
    }
    if (value == -1)
        FUN_0021f800(S, "unexpected end of file");
    unsigned int byteValue = (unsigned char)value;
    if (byteValue != expected)
        FUN_0021f800(S, "bad size of %s (read %d; expected %d)", what, byteValue, expected);
}


// 0x00220300 FUN_00220300 (6 B): matches/0x00220300.cpp
// sym: ?UsesLayeredTexture@d3dLayeredShader@fn_f816444d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int d3dLayeredShader::UsesLayeredTexture() {
    return 1;
}


// 0x00220310 FUN_00220310 (354 B): equivalent/0x00220310.cpp
// sym: _FUN_00220310 @b97c994adb81 @w95d70f35ac3e
// STATUS: equivalent (tools/equiv.py level 3: 3101 inputs, branch coverage 18/20, incomplete)
// LoadHeader: signature, version 5.1, endianness (swap), the chunk format's sizes (4 each) and the test number.
// equiv-conv: FUN_00220220 eax
// equiv-conv: FUN_002202a0 eax edi stack
// equiv-conv: FUN_0021f8c0 ecx eax edx
// equiv-conv: FUN_0021f800 esi stack
// equiv-conv: FUN_00220310 eax
extern "C" void __cdecl FUN_00220310(LuaVMLoadState* S) {
    float x;
    int ch;
    unsigned int n;
    LuaVMZio* z;

    FUN_00220220(S);

    z = S->Z;
    n = z->n;
    z->n = n - 1;
    z = S->Z;
    if (n != 0) {
        const char* p = z->p;
        ch = *(const unsigned char*)p;
        z->p = p + 1;
    } else {
        ch = FUN_0021a550(z);
    }
    if (ch == -1)
        FUN_0021f800(S, "unexpected end of file");

    int version = (unsigned char)ch;
    if (version > 0x51)
        FUN_0021f800(S, "bad version (read %d.%d; expected at %s %d.%d)", version / 16, version % 16, "most", 5, 1);
    if (version < 0x51)
        FUN_0021f800(S, "bad version (read %d.%d; expected at %s %d.%d)", version / 16, version % 16, "least", 5, 1);

    z = S->Z;
    n = z->n;
    z->n = n - 1;
    z = S->Z;
    if (n != 0) {
        const char* p = z->p;
        ch = *(const unsigned char*)p;
        z->p = p + 1;
    } else {
        ch = FUN_0021a550(z);
    }
    if (ch == -1)
        FUN_0021f800(S, "unexpected end of file");

    S->swap = ((char)ch != 1);

    FUN_002202a0(S, 4, "int");
    FUN_002202a0(S, 4, "size_t");
    FUN_002202a0(S, 4, "instruction");
    FUN_002202a0(S, 4, "number");

    FUN_0021f8c0((char*)(void*)(&x), 4, S);
    if ((int)x != 0x1df5e76)
        FUN_0021f800(S, "unknown number format");
}


// 0x00220480 FUN_00220480 (82 B): equivalent/0x00220480.cpp
// sym: _FUN_00220480 @985766694c87 @w7483e75f320a
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 6/6)
// luaU_undump: load a precompiled chunk (the header, then the main function).
// equiv-conv: FUN_00220310 eax
extern "C" LuaVMProto* __cdecl FUN_00220480(LuaVMState* L, LuaVMZio* Z, LuaVMBuffer* buff, const char* name) {
    LuaVMLoadState S;
    if (*name == '@' || *name == '=')
        S.name = name + 1;
    else if (*name == '\x1b')
        S.name = DAT_004271a8;
    else
        S.name = name;
    S.L = L;
    S.Z = Z;
    S.b = buff;
    FUN_00220310(&S);
    return FUN_00220050(&S, 0);
}

} // namespace fn_f816444d

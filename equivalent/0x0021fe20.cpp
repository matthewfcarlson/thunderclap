// STATUS: equivalent (tools/equiv.py level 3: 122 inputs, branch coverage 34/34)
// LoadConstants (nil, number, string constants), then the nested functions.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021f800 esi stack
extern "C" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);
// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char* b, unsigned int size, LuaVMLoadState* S);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
extern "C" char* __cdecl FUN_0021a6b0(LuaVMState* L, LuaVMBuffer* buff, unsigned int n);
extern "C" unsigned int __cdecl FUN_0021a610(LuaVMZio* z, void* b, unsigned int n);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" LuaVMProto* __cdecl FUN_00220050(LuaVMLoadState* S, LuaVMString* p);

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

// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00260a40..0x00260d00 (kind game, layer engine, confidence medium), dominant class om::DynAttr
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/om.h"
#define TREE_TU_BEGIN namespace fn_fcce214a {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fcce214a {} using namespace fn_fcce214a;
#include "engine/om.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char*, const char*, ...);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif
namespace fn_fcce214a {
extern "C" unsigned int FUN_00267f00();
struct Buffer {
    char pad[0x2004];
    char* cursor;
};
} // namespace fn_fcce214a
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl rand();
#endif
namespace fn_fcce214a {
struct Obj {
    char pad[0x2004];
    char* cursor;
};
struct Parser_260b30 {
    char pad[0x2008];
    char* cursor;
    char* end;
};
struct Parser_260b60 {
    char pad0[0x2008];
    const char* cur;    // 0x2008
    const char* end;    // 0x200c
};
class Owner_260be0 {
  public:
    char pad[0x2004];
    int offset;
};
extern "C" char DAT_0042aad0[];
typedef unsigned int u32_260c70;
struct ThisCall_002584d0 {
    void Init(void*, void*, int, int);
};
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);

} // namespace fn_fcce214a

// 0x00260a40 FUN_00260a40 (66 B): matches/0x00260a40.cpp [wrapped: conflict: strlen]
// sym: _FUN_00260a40
namespace fn_00260a40 {
/* size_t: tree_prelude.h */

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char*, const char*, ...);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" size_t strlen(const char*);
#endif

extern "C" unsigned int FUN_00267f80();
struct Obj {
    char pad[0x2004];
    char* p;
};
extern "C" char* __cdecl FUN_00260a40(Obj* o) {
    unsigned int n = FUN_00267f80();
    char* s = o->p;
    sprintf(s, "%u", n);
    o->p += strlen(s) + 1;
    return s;
}
} // namespace fn_00260a40

namespace fn_fcce214a {

// 0x00260a90 FUN_00260a90 (66 B): matches/0x00260a90.cpp
// sym: _FUN_00260a90
extern "C" char* __cdecl FUN_00260a90(Buffer* b) {
    unsigned int n = FUN_00267f00();
    char* s = b->cursor;
    sprintf(s, "%u", n);
    b->cursor += strlen(s) + 1;
    return s;
}


// 0x00260ae0 FUN_00260ae0 (66 B): matches/0x00260ae0.cpp
// sym: _FUN_00260ae0
extern "C" char* __cdecl FUN_00260ae0(Obj* p) {
    int n = rand();
    char* s = p->cursor;
    sprintf(s, "%u", n);
    p->cursor += strlen(s) + 1;
    return s;
}


// 0x00260b30 FUN_00260b30 (47 B): matches/0x00260b30.cpp
// sym: _FUN_00260b30
extern "C" void __cdecl FUN_00260b30(Parser_260b30* p) {
    while (p->cursor < p->end) {
        if (*p->cursor != ' ')
            return;
        ++p->cursor;
    }
}


// 0x00260b60 FUN_00260b60 (126 B): matches/0x00260b60.cpp
// sym: _FUN_00260b60
// FUN_00260b60 @ 0x00260b60
// Skips leading spaces, then advances past one space-delimited token; a parenthesised group
// counts as part of the token and is consumed through its closing parenthesis.
extern "C" void FUN_00260b60(Parser_260b60* p)
{
    while (p->cur < p->end && *p->cur == ' ')
        p->cur++;
    int depth = 0;
    while (p->cur < p->end) {
        char c = *p->cur;
        if (c == '(') {
            depth++;
        } else if (c == ')') {
            if (depth == 0)
                return;
            if (--depth == 0) {
                p->cur++;
                return;
            }
        } else if (c == ' ' && depth == 0) {
            return;
        }
        p->cur++;
    }
}


// 0x00260be0 FUN_00260be0 (120 B): matches/0x00260be0.cpp
// sym: _FUN_00260be0
extern "C" int FUN_00260be0(Owner_260be0* owner, float value) {
    char buffer[256];
    int i = sprintf(buffer, "%f", (double)value);
    --i;
    if (i != 0) {
        do {
            if (buffer[i] != '0') {
                if (buffer[i] == '.')
                    buffer[i] = 0;
                else
                    buffer[i + 1] = 0;
                break;
            }
            --i;
        } while (i != 0);
    }
    int pos = owner->offset;
    owner->offset = pos + i + 1;
    char* src = buffer;
    char c;
    do {
        c = *src;
        src[pos - (hulk_intptr)buffer] = c;
        ++src;
    } while (c);
    return pos;
}


// 0x00260c70 FUN_00260c70 (32 B): matches/0x00260c70.cpp
// sym: @FUN_00260c70@8
extern "C" void* __fastcall FUN_00260c70(void* p, void* edx) {
    HULK_SIZE32(OmDynAttrString, 0x24);
    ((ThisCall_002584d0*)(p))->Init((void*)((hulk_intptr)DAT_004e58d0), (void*)((hulk_intptr)DAT_004e58c8), (int)sizeof(OmDynAttrString), (int)__alignof(OmDynAttrString));
    *(hulk_uintptr*)p = ((hulk_intptr)DAT_0042aad0);
    return p;
}


// 0x00260ce0 om::DynAttr::vfunc_0 (31 B): matches/0x00260ce0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_fcce214a@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fcce214a

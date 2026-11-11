// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028fbc0..0x0028fe80 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f6be11fc {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6be11fc {} using namespace fn_f6be11fc;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f6be11fc {
struct Source_28fbc0 {
    const char *FUN_003469f5();
};
extern "C" Source_28fbc0 *__cdecl FUN_003449e4(const char *name);
struct Owner_28fcf0 {
    void* Get_002314c0();
};
extern "C" int __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
extern "C" const char hulk_at_0048d5bc[];
extern "C" const char hulk_at_0048f610[];
struct Obj_28fd30 {
    Obj_28fd30* Get_00231640();
    Obj_28fd30* Tail_0028fcf0();
    Obj_28fd30* Target();
};
extern int __cdecl FUN_00344e74(Obj_28fd30*, int, void*, void*, int);
extern void* g1_28fd30;
extern void* g2_28fd30;
struct Node { char pad[12]; void* source; };
struct Iterator_28fd70 {
 void* state; void* cursor; Node* node;
 void FUN_002314a0(void*);
 void* FUN_00231640();
 void* FUN_0028fcf0();
 void* FUN_002314c0();
};
extern char DAT_0048f610;
extern char DAT_0048d5bc;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C" bool __cdecl FUN_0028fbc0(const char *, char *, unsigned int);
class Obj_28fe30 {
  public:
    char pad[8];
    int value;
    void reset_0027af00();
    Obj_28fe30* target();
};
typedef unsigned int u32_28fe50;
void __cdecl thunk_FUN_00267090(u32_28fe50);
struct Obj_28fe50 {
    char pad[8];
    u32_28fe50 field;
    void base_0027af50();
    void method();
};


// 0x0028fbc0 FUN_0028fbc0 (225 B): equivalent/0x0028fbc0.cpp
// sym: _FUN_0028fbc0
// STATUS: equivalent (tools/equiv.py level 3: 3058 inputs, branch coverage 29/36, incomplete)
// FUN_0028fbc0 @ 0x0028fbc0
// Strips a leading "class " keyword and any namespace qualifier ("A::B::") from a type name,
// copying the remainder to `out`. Fails (and terminates `out`) when it does not fit.
extern "C" bool FUN_0028fbc0(const char *name, char *out, unsigned int size)
{
    char buf[0x100];
    if (!name)
        return false;
    const char *src = FUN_003449e4(name)->FUN_003469f5();
    char *dst = buf;
    char c;
    do {
        c = *src++;
        *dst++ = c;
    } while (c);

    char *p = buf;
    if (buf[0] == ' ') {
        do {
            p++;
        } while (*p == ' ');
    }
    if (p[0] == 'c' && p[1] == 'l' && p[2] == 'a' && p[3] == 's' && p[4] == 's')
        p += 5;
    if (*p == ' ') {
        do {
            p++;
        } while (*p == ' ');
    }
    if (*p) {
        const char *s = p;
        c = *s;
        do {
            if (c == ':' && s[1] == ':')
                p = (char *)s + 2;
            c = s[1];
            s++;
        } while (c);
    }
    unsigned int len = 0;
    while (p[len])
        len++;
    if (len >= size - 1) {
        *out = 0;
        return false;
    }
    const char *from = p;
    do {
        c = *from++;
        *out++ = c;
    } while (c);
    return true;
}


// 0x0028fcb0 FUN_0028fcb0 (1 B): matches/0x0028fcb0.cpp
// sym: _FUN_0028fcb0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_0028fcb0() {}


// 0x0028fcc0 FUN_0028fcc0 (1 B): matches/0x0028fcc0.cpp
// sym: _FUN_0028fcc0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_0028fcc0() {}


// 0x0028fcf0 FUN_0028fcf0 (61 B): matches/0x0028fcf0.cpp
// sym: ?FUN_0028fcf0@fn_f6be11fc@@YIPAXPAUOwner_28fcf0@1@PAX@Z
void* __fastcall FUN_0028fcf0(Owner_28fcf0* self, void*) {
    void* p = self->Get_002314c0();
    while (p) {
        if (FUN_00344e74(p, 0, hulk_at_0048d5bc, hulk_at_0048f610, 0))
            break;
        p = self->Get_002314c0();
    }
    return p;
}


// 0x0028fd30 FUN_0028fd30 (52 B): matches/0x0028fd30.cpp
// sym: ?Target@Obj_28fd30@fn_f6be11fc@@QAEPAU12@XZ
// Same code shape as 0x001a9260 (propagated; names are from that function)
Obj_28fd30* Obj_28fd30::Target() {
    Obj_28fd30* p = Get_00231640();
    if (FUN_00344e74(p, 0, &g1_28fd30, &g2_28fd30, 0))
        return p;
    return Tail_0028fcf0();
}


// 0x0028fd70 FUN_0028fd70 (184 B): equivalent/0x0028fd70.cpp
// sym: _FUN_0028fd70
// STATUS: equivalent (tools/equiv.py level 3: 191 inputs, branch coverage 12/12)
// FUN_0028fd70 @ 0x0028fd70
extern "C" void __cdecl FUN_0028fd70(Node* node) {
 struct Workspace { Iterator_28fd70 it; char buffer[256]; } work;
 work.it.FUN_002314a0(node->source);
 work.it.node = node;
 void* item = work.it.FUN_00231640();
 if (!FUN_00344e74(item, 0, &DAT_0048d5bc, &DAT_0048f610, 0)) item = work.it.FUN_0028fcf0();
 while (item) {
  FUN_0028fbc0((const char *)(void *)item, (char *)(void *)(work.buffer), 255);
  item = work.it.FUN_002314c0();
  while (item && !FUN_00344e74(item, 0, &DAT_0048d5bc, &DAT_0048f610, 0)) item = work.it.FUN_002314c0();
 }
}


// 0x0028fe30 FUN_0028fe30 (19 B): matches/0x0028fe30.cpp
// sym: ?target@Obj_28fe30@fn_f6be11fc@@QAEPAV12@XZ
Obj_28fe30* Obj_28fe30::target() {
    reset_0027af00();
    value = 0;
    return this;
}


// 0x0028fe50 FUN_0028fe50 (34 B): matches/0x0028fe50.cpp
// sym: ?method@Obj_28fe50@fn_f6be11fc@@QAEXXZ
void Obj_28fe50::method() {
    if (field) {
        thunk_FUN_00267090(field);
        field = 0;
    }
    base_0027af50();
}

} // namespace fn_f6be11fc

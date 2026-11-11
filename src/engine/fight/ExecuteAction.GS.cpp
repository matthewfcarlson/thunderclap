// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002393a0..0x00239d50 (kind game, layer engine, confidence high), dominant class fight::ExecuteAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7a4ec2a {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7a4ec2a {} using namespace fn_f7a4ec2a;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f7a4ec2a {
struct Item_2394c0 {
    char pad0[0xc];
    unsigned int bits;      // 0xc
    float x;                // 0x10
    float y;                // 0x14
};
struct Part_2394c0 {
    void FUN_00232060(struct Owner_2394c0 *owner, hulk_intptr a, int b, int c);
    void FUN_002320d0(struct Owner_2394c0 *owner, hulk_intptr a, int b);
};
struct Child_2394c0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float getX();                                  // 0x18
    virtual float getY();                                  // 0x1c
    virtual Part_2394c0 *lookup(Part_2394c0 *a, int b);                  // 0x20
    virtual int check(struct Owner_2394c0 *owner, Part_2394c0 *a, int b); // 0x24
    virtual Item_2394c0 *make(struct Owner_2394c0 *owner, Part_2394c0 *a, int b); // 0x28
    Child_2394c0 *next;            // 0x4
    int kind;               // 0x8
};
struct Owner_2394c0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Owner_2394c0 *find(int a, int b);  // 0x20
    char pad4[0x28 - 4];
    Child_2394c0 *first;           // 0x28
};
struct Slots_2394c0 {
    char pad0[0x20];
};
struct Sub_2394c0 {
    void FUN_00232290(Item_2394c0 *item);
    void FUN_00232030(Owner_2394c0 *owner);
    void FUN_002322f0(int a, int b);
};
int __cdecl FUN_00238190(int n);
extern "C" int __cdecl FUN_00266da0(int h);
struct Check_2394c0 {
    char FUN_00236f40(int a, int b, int c);
};
class ExecuteAction {
public:
    int vptr;
    char pad4[8];
    unsigned int flags;     // 0xc
    char pad10[0x1c - 0x10];
    int field1c;
    char pad20[4];
    Owner_2394c0 *owner;           // 0x24
    int field28;
    Check_2394c0 *field2c;
    Part_2394c0 *part;             // 0x30
    int field34;
    Sub_2394c0 sub;                // 0x38
    char pad39[0x60 - 0x39];
    int field60;
    char done;              // 0x64
    char FUN_002394c0(int a1, int a2);
};


// 0x002394c0 fight::ExecuteAction::vfunc_3 (546 B): equivalent/0x002394c0.cpp
// sym: ?FUN_002394c0@ExecuteAction@fn_f7a4ec2a@@QAEDHH@Z @1ecbd1e80efa @w75cca5a01718
// STATUS: equivalent (tools/equiv.py level 3: 20022 inputs, branch coverage 43/44, incomplete)
// fight::ExecuteAction::vfunc_3 @ 0x002394c0
char ExecuteAction::FUN_002394c0(int a1, int a2)
{
    Part_2394c0 *seen[8];
    char mark[8];
    int handle = FUN_00266da0(FUN_00238190(3));
    field60 = a1;

    if (owner == 0 || (field2c != 0 && !field2c->FUN_00236f40(field1c, field34, 0))) {
        FUN_00266da0(handle);
        return 0;
    }

    Owner_2394c0 *found = owner->find(field34, 0);
    if (found == 0) {
        FUN_00266da0(handle);
        return 0;
    }

    int count = 0;
    int allow = 1;
    for (Child_2394c0 *c = found->first; c != 0; c = c->next) {
        int kind = c->kind;
        Part_2394c0 *r = c->lookup(part, field34);
        if (part == r) {
            Item_2394c0 *it = c->make(found, part, field34);
            if (it) {
                it->x = c->getX();
                it->y = c->getY();
                it->bits ^= (it->bits ^ kind) & 3;
                sub.FUN_00232290(it);
            }
            if (kind == 0)
                allow = 0;
        } else if (r != 0) {
            int idx = 0;
            while (idx < count && seen[idx] != r)
                ++idx;
            if (idx >= count) {
                if (count < 8) {
                    idx = count;
                    seen[count] = r;
                    mark[count] = 0;
                    ++count;
                }
            }
            if (idx < count) {
                if (kind == 0 || (kind == 3 && c->check(found, r, field34) == 0))
                    mark[idx] = 1;
            }
        }
    }

    sub.FUN_00232030(found);
    flags ^= (flags ^ allow) & 3;
    for (int i = 0; i < count; ++i) {
        if (mark[i])
            seen[i]->FUN_00232060(found, (hulk_intptr)part, field34, field28);
        else
            seen[i]->FUN_002320d0(found, (hulk_intptr)part, field34);
    }
    sub.FUN_002322f0(field60, a2);
    done = 1;
    char res = ((char)((owners::C_231ee0 *)&sub)->FUN_00231ee0());
    FUN_00266da0(handle);
    return res;
}

} // namespace fn_f7a4ec2a

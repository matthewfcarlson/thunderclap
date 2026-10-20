// STATUS: equivalent (tools/equiv.py level 3: 212 inputs, branch coverage 64/68, incomplete)
// FUN_00311d50 @ 0x00311d50
#include "compat/ptr.h"
extern "C" void *memset(void *, int, unsigned int);

struct Z;

struct BoneList;

struct Y_311d50 {
    Z *FUN_0030f100();
};

struct X_311d50 {
    Y_311d50 *FUN_0030edf0();
};

struct SkeletonData_311d50 {
    char pad00[0x28];
    unsigned short *parent;
};

struct Source_311d50 {
    char pad00[8];
    SkeletonData_311d50 *data;
    X_311d50 *FUN_0030f490(int id);
    int FUN_0030f450();
};

class Bone_311d50 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(Z *z);
    char pad04[4];
    int id;
    int parentIndex;
    char pad10[0x1c - 0x10];
    Bone_311d50 *parent;
    Bone_311d50 **childBegin;
    Bone_311d50 **childEnd;
    Bone_311d50 **childCapEnd;
    char pad2c[0xe4 - 0x2c];
    float weight;
    char padE8[0xef - 0xe8];
    char marked;
};

typedef void (__fastcall *BoneSlot10)(Bone_311d50 *self, int unused, Z *z);

static inline void **VtableOf(Bone_311d50 *b)
{
    return *(void ***)b;
}

void *FUN_0008d6d0(hulk_uintptr size);
void *FUN_00266e00(int kind, unsigned int size);
void FUN_00267090(void *p);
void FUN_00311c20(Bone_311d50 **first, Bone_311d50 **last, hulk_intptr n);

class SkeletonBuilder {
public:
    char pad00[0x1f8];
    Bone_311d50 **list;
    Bone_311d50 **table;
    int count;
    int capacity;
    Source_311d50 *source;
    void FUN_00311d50();
    void FUN_00310ec0();
};

void SkeletonBuilder::FUN_00311d50()
{
    SkeletonData_311d50 *data = source->data;
    if (table != 0) {
        for (int i = 0; i < count; i++) {
            int id = list[i]->id;
            X_311d50 *x = source->FUN_0030f490(id);
            void **vt = VtableOf(table[id]);
            Z *z = x->FUN_0030edf0()->FUN_0030f100();
            ((BoneSlot10)vt[10])(table[id], 0, z);
        }
        FUN_00310ec0();
        return;
    }
    capacity = source->FUN_0030f450();
    Bone_311d50 **mem = (Bone_311d50 **)FUN_0008d6d0(capacity * 4);
    table = mem;
    memset(mem, 0, capacity * 4);
    for (int i = 0; i < count; i++) {
        Bone_311d50 *b = list[i];
        table[b->id] = b;
    }
    int *counts = (int *)FUN_00266e00(1, capacity * 4);
    memset(counts, 0, capacity * 4);
    for (int i = 0; i < count; i++) {
        int id = list[i]->id;
        int p = data->parent[id];
        for (;;) {
            if (table[p] != 0 && id != p) {
                counts[p]++;
                break;
            }
            p = data->parent[p];
            if (p <= 0) {
                break;
            }
        }
        if (i > 0 && p == 0 && table[0] != 0 && list[i]->parent == 0) {
            counts[0]++;
        }
    }
    for (int i = 0; i < count; i++) {
        Bone_311d50 *b = table[list[i]->id];
        int n = counts[list[i]->id];
        Bone_311d50 **begin;
        if (n != 0) {
            begin = (Bone_311d50 **)FUN_0008d6d0(n * 4);
            b->childBegin = begin;
            if (begin != 0) {
                b->childCapEnd = begin + n;
            } else {
                begin = 0;
                b->childCapEnd = 0;
            }
        } else {
            b->childBegin = 0;
            begin = 0;
            b->childCapEnd = 0;
        }
        b->childEnd = begin;
    }
    FUN_00267090(counts);
    for (int i = 0; i < count; i++) {
        Bone_311d50 *b = list[i];
        int id = b->id;
        int p = data->parent[id];
        b->parentIndex = p;
        for (;;) {
            if (table[p] != 0 && id != p) {
                Bone_311d50 *par = table[p];
                list[i]->parent = par;
                Bone_311d50 *owner = table[p];
                if (owner->childEnd < owner->childCapEnd) {
                    Bone_311d50 **e = owner->childEnd;
                    owner->childEnd = e + 1;
                    if (e != 0) {
                        *e = list[i];
                    }
                }
                owner = table[p];
                FUN_00311c20(owner->childBegin, owner->childEnd, owner->childEnd - owner->childBegin);
                break;
            }
            p = data->parent[p];
            if (p <= 0) {
                break;
            }
        }
        if (i > 0 && p == 0 && table[0] != 0 && list[i]->parent == 0) {
            Bone_311d50 *root = table[0];
            list[i]->parent = root;
            root = table[0];
            if (root->childEnd < root->childCapEnd) {
                Bone_311d50 **e = root->childEnd;
                root->childEnd = e + 1;
                if (e != 0) {
                    *e = list[i];
                }
            }
            root = table[0];
            FUN_00311c20(root->childBegin, root->childEnd, root->childEnd - root->childBegin);
        }
        Bone_311d50 *cur = list[i];
        if (cur->weight > 0.0f || (cur->parent != 0 && cur->parent->marked == 1)) {
            cur->marked = 1;
        }
        X_311d50 *x = source->FUN_0030f490(id);
        void **vt = VtableOf(table[id]);
        Z *z = x->FUN_0030edf0()->FUN_0030f100();
        ((BoneSlot10)vt[10])(table[id], 0, z);
    }
    FUN_00310ec0();
}

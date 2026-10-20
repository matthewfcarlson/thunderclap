// STATUS: equivalent (tools/equiv.py level 3: 2142 inputs, branch coverage 35/36, incomplete)
// FUN_0030a9d0 @ 0x0030a9d0
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"

struct Vec3_30a9d0 {
    float x, y, z;
    void FUN_000111b0(Vec3_30a9d0* a, Vec3_30a9d0* b);
};

struct Elem_30a9d0 {
    char pad00[4];
    Vec3_30a9d0 p4;
    Vec3_30a9d0 p10;
    char pad1c[0x64 - 0x1c];
    void FUN_002fd730();
};

struct Table_30a9d0 {
    char pad00[0x8c];
    Elem_30a9d0* elems;
};

struct Node {
    char pad00[8];
    int f8;
    char pad0c[0x1c - 0xc];
    Node* next;
};

struct Owner_30a9d0 {
    char pad00[0x10];
    Table_30a9d0* table;
    char pad14[0x98 - 0x14];
    Vec3_30a9d0 pos98;
    char padA4[0x214 - 0xa4];
    Node* list;
    char pad218[0x224 - 0x218];
    float f224;
};

struct Link_30a9d0 {
    char pad00[0xd4];
    Vec3_30a9d0 pos;
};


class Body_30a9d0;

class Body_30a9d0 {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22(Vec3_30a9d0* out);
    virtual void v23();
    virtual void v24(Vec3_30a9d0* v);
    virtual void v25();
    virtual char v26(Vec3_30a9d0* c, Vec3_30a9d0* v);
    char b4;
    char pad05;
    short w6;
    int f8;
    char pad0c[0x18 - 0xc];
    Owner_30a9d0* owner;
    Link_30a9d0* link;
    Body_30a9d0** childBegin;
    Body_30a9d0** childEnd;
    char pad28[0x80 - 0x28];
    Vec3_30a9d0 v80;
    char pad8c[0xd4 - 0x8c];
    Vec3_30a9d0 pos;
    char pade0[0xe8 - 0xe0];
    float fe8;
    char bec;
    void FUN_0030a9d0(Vec3_30a9d0 a, Vec3_30a9d0 b, char flag);
};

void Body_30a9d0::FUN_0030a9d0(Vec3_30a9d0 a, Vec3_30a9d0 b, char flag)
{
    struct Frame {
        Vec3_30a9d0 c;
        Vec3_30a9d0 v;
        float dx;
        float spare[2];
    } f;
    float px, py;
    if (link != 0) {
        px = link->pos.x;
        py = link->pos.y;
        f.v.z = link->pos.z;
    } else {
        px = owner->pos98.x;
        py = owner->pos98.y;
        f.v.z = owner->pos98.z;
    }
    f.dx = pos.x - px;
    double dy = pos.y - py;
    double dz = pos.z - f.v.z;
    float dx = f.dx;
    Vec3_30a9d0& c = f.c;
    c.x = b.y * dz - b.z * dy;
    c.y = b.z * dx - dz * b.x;
    c.z = dy * b.x - b.y * dx;
    Elem_30a9d0* e = owner->table->elems + f8;
    a.x = c.x + a.x;
    a.y = a.y + c.y;
    a.z = a.z + c.z;
    e->FUN_002fd730();
    e->p4.x = a.x + e->p4.x;
    e->p4.y = a.y + e->p4.y;
    e->p4.z = a.z + e->p4.z;
    if (flag == 1) {
        Node* n = owner->list;
        char found = 0;
        if (f8 < n->f8) {
            while (n->f8 > f8) {
                n = n->next;
                if (n == 0)
                    break;
                if (n->f8 == f8) {
                    found = 1;
                    break;
                }
            }
        }
        flag = found;
    }
    if (b4) {
        if (!bec && !flag && w6 > 0 && (void*)this != (void*)owner->list) {
            Owner_30a9d0* o = owner;
            c.FUN_000111b0(&b, &v80);
            c.x = c.x + a.x;
            c.y = a.y + c.y;
            c.z = a.z + c.z;
            float k = DAT_004d3180 * o->f224;
            if (c.z * c.z + c.y * c.y + c.x * c.x > k * k) {
                Vec3_30a9d0& v = f.v;
                if (v26(&c, &v)) {
                    b.x = v.x + b.x;
                    b.y = v.y + b.y;
                    b.z = v.z + b.z;
                    v24(&v);
                }
            }
        }
        if (fe8 > 0.0f || bec) {
            Vec3_30a9d0& v = f.v;
            v22(&v);
            v23();
            fe8 = 0.0f;
            b.x = v.x + b.x;
            b.y = v.y + b.y;
            b.z = v.z + b.z;
        }
    }
    Elem_30a9d0* e2 = owner->table->elems + f8;
    e2->FUN_002fd730();
    e2->p10.x = b.x + e2->p10.x;
    e2->p10.y = b.y + e2->p10.y;
    e2->p10.z = b.z + e2->p10.z;
    hulk_uintptr n = childEnd - childBegin;
    if (n != 0) {
        for (unsigned int i = 0; i < (unsigned int)(childEnd - childBegin); i++)
            childBegin[i]->FUN_0030a9d0(a, b, flag);
    }
    v3();
}

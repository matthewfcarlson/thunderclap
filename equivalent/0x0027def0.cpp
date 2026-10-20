// STATUS: equivalent (tools/equiv.py level 3: 60 inputs, branch coverage 59/64, incomplete)
// FUN_0027def0 @ 0x0027def0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "compat/ptr.h"
extern "C" void *memset(void *dst, int c, unsigned int n);

void *FUN_0008d690(hulk_uintptr size);
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d6d0(hulk_uintptr size);

struct Name_27def0 {
    int w0;
    int w1;
    void FUN_0027af70(Name_27def0 *other);
};

struct Matrix16_27def0 {
    unsigned int w[16];
    void FUN_0022b980();
};

class RefCounted_27def0 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Flag_27def0 {
    void FUN_00284ad0(char value);
};

class Material_27def0 : public RefCounted_27def0 {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10();
    virtual int Hash();
    char pad04[0x44];
    int f48;
    Flag_27def0 *f4c;
    Flag_27def0 *f50;
    void FUN_002998d0(int arg);
};

struct Source_27def0 {
    char pad0[8];
    Name_27def0 name;
    void *source;
};

class Collider_27def0 : public RefCounted_27def0 {
public:
    char pad04[4];
    Name_27def0 name;
    void *source;
    Collider_27def0 *FUN_002fe1a0(void *source);
};

struct Shape_27def0 {
    char pad0[0x2c];
    unsigned int priority;
    char pad30[0x1c];
    Source_27def0 *src;
};

struct ShapeObj_27def0 {
    ShapeObj_27def0 *FUN_002f3630(void *source);
};

struct PtrVec_27def0 {
    Shape_27def0 **begin;
    Shape_27def0 **end;
};

class Holder_27def0 : public RefCounted_27def0 {
public:
    char pad04[0xc];
    void *p10;
    Holder_27def0 *FUN_002fc740(void *a, int b, int c, int d);
    void FUN_002fc670(int v);
};

struct Kind_27def0 {
    char pad0[0x78];
    int kind;
};

class Part_27def0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Material_27def0 *v4();
};

class Group_27def0 : public RefCounted_27def0 {
public:
    char pad04[4];
    Name_27def0 name;
    Part_27def0 *p10;
    Kind_27def0 *f14;
    Part_27def0 *part() { return p10; }
    int f18;
    PtrVec_27def0 shapes;
};

namespace pure3d {
class __declspec(novtable) DrawableHierarchy {
public:
    virtual void d0();
    char pad4[4];
    Name_27def0 name;
    char pad10[0x30];
    void FUN_002a3480();
    DrawableHierarchy() throw() { FUN_002a3480(); }
};

namespace prop {
class StateProp : public DrawableHierarchy {
public:
    virtual void s1();
    int f40;
    int f44;
    Matrix16_27def0 matrix;
    int f88;
    char b8c;
    char pad8d[3];
    int f90;
    int f94;
    Group_27def0 *group;
    Material_27def0 *material;
    Holder_27def0 *holder;
    void *table;
    unsigned int count;
    Collider_27def0 **colliders;
    char dirty;
    char padb1[3];
    int fb4;
    int tail[12];
    void FUN_0027d780();

    StateProp(Group_27def0 *a, int b);
};

StateProp::StateProp(Group_27def0 *a, int b)
{
    f40 = b;
    f44 = 0;
    f88 = 0;
    b8c = 1;
    f90 = 0;
    group = 0;
    material = 0;
    holder = 0;
    table = 0;
    count = 0;
    colliders = 0;
    dirty = 0;
    fb4 = 0;
    name.FUN_0027af70(&a->name);
    if (a)
        a->AddRef();
    if (group)
        group->Release();
    group = a;

    Material_27def0 *m = a->part()->v4();
    if (m)
        m->AddRef();
    if (material)
        material->Release();
    material = m;
    if (m->f48 == 0)
        m->FUN_002998d0(0);
    if (material->f4c)
        material->f4c->FUN_00284ad0(1);
    if (material->f50)
        material->f50->FUN_00284ad0(1);

    matrix.FUN_0022b980();

    Kind_27def0 *k = group->f14;
    if (k) {
        bool two = k->kind == 2;
        Holder_27def0 *h = (Holder_27def0 *)FUN_0008d690(0x18);
        if (h) {
            Kind_27def0 *fk = group->f14;
            int fv = group->f18;
            h = h->FUN_002fc740(fk, fv, material->Hash(), two);
        }
        if (h)
            h->AddRef();
        if (holder)
            holder->Release();
        holder = h;
        h->FUN_002fc670(2);
        if (material->f4c)
            material->f4c->FUN_00284ad0(1);
        if (material->f50)
            material->f50->FUN_00284ad0(1);
    }

    if ((hulk_uintptr)a >= 1u) {
        if (((int)((char *)a->shapes.end - (char *)a->shapes.begin) & ~3) > 0) {
            int i = 0;
            do {
                unsigned int v = a->shapes.begin[i]->priority;
                if (v > count)
                    count = v;
                i++;
            } while (i < (a->shapes.end - a->shapes.begin));
        }
        void *t = FUN_0008d6d0(count * 24);
        table = t;
        memset(t, 0, count * 24);
    }

    colliders = (Collider_27def0 **)FUN_0008d6d0((a->shapes.end - a->shapes.begin) * 4);
    int fin = 0;
    if (((hulk_uintptr)a >= 1u) && ((int)((char *)a->shapes.end - (char *)a->shapes.begin) & ~3) > 0) {
        int j = 0;
        do {
            Source_27def0 *s = a->shapes.begin[j]->src;
            if (s == 0) {
                colliders[j] = 0;
            } else {
                Collider_27def0 *found = 0;
                for (int k2 = 0; k2 < j; k2++) {
                    Collider_27def0 *c = colliders[k2];
                    if (c != 0 && c->name.w0 == s->name.w0 && c->name.w1 == s->name.w1) {
                        found = c;
                        break;
                    }
                }
                if (found) {
                    colliders[j] = found;
                    colliders[j]->AddRef();
                    dirty = 1;
                } else {
                    ShapeObj_27def0 *so = (ShapeObj_27def0 *)FUN_0008d690(0xd4);
                    void *sobj;
                    if (so)
                        sobj = so->FUN_002f3630(s->source);
                    else
                        sobj = 0;
                    Collider_27def0 *w = (Collider_27def0 *)thunk_FUN_0008d690(0x18);
                    if (w)
                        w = w->FUN_002fe1a0(sobj);
                    colliders[j] = w;
                    colliders[j]->name.FUN_0027af70(&s->name);
                    colliders[j]->AddRef();
                    dirty = 1;
                }
            }
            j++;
        } while (j < (a->shapes.end - a->shapes.begin));
    }
    f94 = fin;
    memset(tail, 0, sizeof(tail));
    FUN_0027d780();
}
}
}

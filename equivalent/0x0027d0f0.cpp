// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 40/40)
// FUN_0027d0f0 @ 0x0027d0f0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
extern "C" void *memset(void *dst, int c, unsigned int n);

void *FUN_0008d690(unsigned int size);
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d6d0(unsigned int size);

struct Name_27d0f0 {
    char data[8];
    void FUN_0027af70(Name_27d0f0 *other);
};

struct Matrix16_27d0f0 {
    unsigned int w[16];
};

class RefCounted_27d0f0 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Flag_27d0f0 {
    void FUN_00284ad0(char value);
};

class Material_27d0f0 : public RefCounted_27d0f0 {
public:
    virtual void v2();
    virtual void v3();
    virtual Material_27d0f0 *Clone();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10();
    virtual int Hash();
    char pad04[0x44];
    int f48;
    Flag_27d0f0 *f4c;
    Flag_27d0f0 *f50;
    void FUN_002998d0(int arg);
};

class WorldCollisionObject_27d0f0 : public RefCounted_27d0f0 {
public:
    char pad04[0xc];
    void *source;
    WorldCollisionObject_27d0f0 *FUN_002fe1a0(void *source);
};

struct Shape_27d0f0 {
    char pad0[0x10];
    void *source;
    char pad14[0x18];
    unsigned int priority;
    char pad30[0x1c];
};

struct CollisionMesh_27d0f0 {
    CollisionMesh_27d0f0 *FUN_002f3630(void *source);
    void FUN_002f39e0(Matrix16_27d0f0 *m);
};

struct PtrVec_27d0f0 {
    Shape_27d0f0 **begin;
    Shape_27d0f0 **end;
};

class PhysicsInstance_27d0f0;

class Group_27d0f0 : public RefCounted_27d0f0 {
public:
    char pad04[4];
    Name_27d0f0 name;
    char pad10[4];
    int f14;
    int f18;
    PtrVec_27d0f0 shapes;
};

struct Part_27d0f0 {
    char pad[0x10];
    Part_27d0f0 *p10;
};

class PhysicsInstance_27d0f0 : public RefCounted_27d0f0 {
public:
    char pad04[0xc];
    Part_27d0f0 *p10;
    PhysicsInstance_27d0f0 *FUN_002fc740(int a, int b, int c, int d);
    void *FUN_002fc6f0();
    void FUN_002fc700(void *a, int b);
};

namespace pure3d {
class __declspec(novtable) DrawableHierarchy {
public:
    virtual void d0();
    char pad4[4];
    Name_27d0f0 name;
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
    Matrix16_27d0f0 matrix;
    int f88;
    char b8c;
    char pad8d[3];
    int f90;
    int f94;
    Group_27d0f0 *group;
    Material_27d0f0 *material;
    PhysicsInstance_27d0f0 *holder;
    void *table;
    unsigned int count;
    WorldCollisionObject_27d0f0 **colliders;
    char dirty;

    StateProp(StateProp *src);
};

StateProp::StateProp(StateProp *src)
{
    f40 = src->f40;
    f44 = src->f44;
    f88 = 0;
    b8c = src->b8c;
    f90 = 0;
    group = 0;
    material = 0;
    holder = 0;
    table = 0;
    count = 0;
    dirty = 0;
    name.FUN_0027af70(&src->group->name);

    Group_27d0f0 *g = src->group;
    if (g)
        g->AddRef();
    if (group)
        group->Release();
    group = g;

    Material_27d0f0 *m = src->material->Clone();
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

    matrix = src->matrix;

    if (((int)((char *)group->shapes.end - (char *)group->shapes.begin) & ~3) > 0) {
        int i = 0;
        do {
            WorldCollisionObject_27d0f0 *c = src->colliders[i];
            if (c == 0) {
                colliders[i] = 0;
            } else {
                void *source = c->source;
                CollisionMesh_27d0f0 *s = (CollisionMesh_27d0f0 *)FUN_0008d690(0xd4);
                CollisionMesh_27d0f0 *obj;
                if (s)
                    obj = s->FUN_002f3630(source);
                else
                    obj = 0;
                obj->FUN_002f39e0(&matrix);
                WorldCollisionObject_27d0f0 *w = (WorldCollisionObject_27d0f0 *)thunk_FUN_0008d690(0x18);
                if (w)
                    w = w->FUN_002fe1a0(obj);
                colliders[i] = w;
                colliders[i]->AddRef();
                dirty = 1;
            }
            i++;
        } while (i < (group->shapes.end - group->shapes.begin));
    }

    if (group->f14) {
        PhysicsInstance_27d0f0 *h = (PhysicsInstance_27d0f0 *)FUN_0008d690(0x18);
        if (h) {
            int a = group->f14;
            int b = group->f18;
            int tmp1 = material->Hash();
            h = h->FUN_002fc740(a, b, tmp1, 0);
        }
        if (h)
            h->AddRef();
        if (holder)
            holder->Release();
        holder = h;
        void * tmp1 = src->holder->FUN_002fc6f0();
        holder->FUN_002fc700(tmp1, 0);
    }

    if (group) {
        if (((int)((char *)group->shapes.end - (char *)group->shapes.begin) & ~3) > 0) {
            int i = 0;
            do {
                unsigned int v = group->shapes.begin[i]->priority;
                if (v > count)
                    count = v;
                i++;
            } while (i < (group->shapes.end - group->shapes.begin));
        }
        table = FUN_0008d6d0(count * 24);
        memset(table, 0, count * 24);
    }
    f94 = 0;
}
}
}

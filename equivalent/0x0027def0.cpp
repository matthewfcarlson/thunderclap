// STATUS: equivalent (tools/equiv.py level 3: 60 inputs, branch coverage 59/64, incomplete)
// FUN_0027def0 @ 0x0027def0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
extern "C" void *memset(void *dst, int c, unsigned int n);

void *FUN_0008d690(unsigned int size);
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d6d0(unsigned int size);

struct Name {
    int w0;
    int w1;
    void FUN_0027af70(Name *other);
};

struct Matrix16 {
    unsigned int w[16];
    void FUN_0022b980();
};

class RefCounted {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Flag {
    void FUN_00284ad0(char value);
};

class Material : public RefCounted {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10();
    virtual int Hash();
    char pad04[0x44];
    int f48;
    Flag *f4c;
    Flag *f50;
    void FUN_002998d0(int arg);
};

struct Source {
    char pad0[8];
    Name name;
    void *source;
};

class Collider : public RefCounted {
public:
    char pad04[4];
    Name name;
    void *source;
    Collider *FUN_002fe1a0(void *source);
};

struct Shape {
    char pad0[0x2c];
    unsigned int priority;
    char pad30[0x1c];
    Source *src;
};

struct ShapeObj {
    ShapeObj *FUN_002f3630(void *source);
};

struct PtrVec {
    Shape **begin;
    Shape **end;
};

class Holder : public RefCounted {
public:
    char pad04[0xc];
    void *p10;
    Holder *FUN_002fc740(void *a, int b, int c, int d);
    void FUN_002fc670(int v);
};

struct Kind {
    char pad0[0x78];
    int kind;
};

class Part {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Material *v4();
};

class Group : public RefCounted {
public:
    char pad04[4];
    Name name;
    Part *p10;
    Kind *f14;
    Part *part() { return p10; }
    int f18;
    PtrVec shapes;
};

namespace pure3d {
class __declspec(novtable) DrawableHierarchy {
public:
    virtual void d0();
    char pad4[4];
    Name name;
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
    Matrix16 matrix;
    int f88;
    char b8c;
    char pad8d[3];
    int f90;
    int f94;
    Group *group;
    Material *material;
    Holder *holder;
    void *table;
    unsigned int count;
    Collider **colliders;
    char dirty;
    char padb1[3];
    int fb4;
    int tail[12];
    void FUN_0027d780();

    StateProp(Group *a, int b);
};

StateProp::StateProp(Group *a, int b)
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

    Material *m = a->part()->v4();
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

    Kind *k = group->f14;
    if (k) {
        bool two = k->kind == 2;
        Holder *h = (Holder *)FUN_0008d690(0x18);
        if (h) {
            Kind *fk = group->f14;
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

    if ((unsigned int)a >= 1u) {
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

    colliders = (Collider **)FUN_0008d6d0((a->shapes.end - a->shapes.begin) * 4);
    int fin = 0;
    if (((unsigned int)a >= 1u) && ((int)((char *)a->shapes.end - (char *)a->shapes.begin) & ~3) > 0) {
        int j = 0;
        do {
            Source *s = a->shapes.begin[j]->src;
            if (s == 0) {
                colliders[j] = 0;
            } else {
                Collider *found = 0;
                for (int k2 = 0; k2 < j; k2++) {
                    Collider *c = colliders[k2];
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
                    ShapeObj *so = (ShapeObj *)FUN_0008d690(0xd4);
                    void *sobj;
                    if (so)
                        sobj = so->FUN_002f3630(s->source);
                    else
                        sobj = 0;
                    Collider *w = (Collider *)thunk_FUN_0008d690(0x18);
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

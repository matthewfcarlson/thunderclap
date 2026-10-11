// STATUS: equivalent (tools/equiv.py level 3: 8 inputs, branch coverage 6/6)
// pure3d::DrawableContainer::vfunc_12 @ 0x002a4570
struct V3 { float x, y, z; };

struct Sphere { float x, y, z, r; };

struct Box {
    V3 min;
    V3 max;
    void FUN_000a87f0(V3* p);
    Sphere* FUN_000a8890(Sphere* out);
};

union Temp {
    Box box;
    Sphere sphere;
};

class Child {
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
    char pad[0x14 - 4];
    Box box;
};

struct Slot {
    Child* child;
    char pad[12];
};

class Container {
public:
    void run();
    char p0[0x14];
    Box box;
    Sphere sphere;
    char p1[0x48 - 0x3c];
    Slot* begin;
    Slot* end;
};

void Container::run()
{
    unsigned int count = (unsigned int)(end - begin);
    Temp t;
    if (count == 0) {
        box.min.x = 0;
        box.min.y = 0;
        box.min.z = 0;
        box.max.x = 1.0f;
        box.max.y = 1.0f;
        box.max.z = 1.0f;
    } else {
        Child* first = begin[0].child;
        first->v10();
        t.box = first->box;
        box = t.box;
        for (unsigned int i = 1; i < count; i++) {
            Child* c = begin[i].child;
            c->v10();
            t.box = c->box;
            box.FUN_000a87f0(&t.box.min);
            box.FUN_000a87f0(&t.box.max);
        }
    }
    Sphere* s = box.FUN_000a8890(&t.sphere);
    sphere = *s;
}

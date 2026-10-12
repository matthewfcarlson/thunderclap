// STATUS: equivalent (tools/equiv.py level 3: 126 inputs, branch coverage 24/24)
// FUN_002a41e0 @ 0x002a41e0
class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
    virtual void v8(int a);
};
class Child {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b);
};
class Source {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int a);
    virtual int v4(int a);
};
struct Entry {
    Owner* owner;
    Child** begin;
    Child** end;
    Child** cap;
};
class Group;
class Parent {
public:
    void FUN_0029b750(Group* g, int zero, int arg);
};
class Group {
public:
    char pad0[0x10];
    Source* source;
    char pad14[0x48 - 0x14];
    Entry* entries;
    Entry* entriesEnd;
    void FUN_002a41e0(Parent* parent, int arg);
};

void Group::FUN_002a41e0(Parent* parent, int arg)
{
    if (parent != 0) {
        parent->FUN_0029b750(this, 0, arg);
        return;
    }
    unsigned int count = (unsigned int)(entriesEnd - entries);
    if (source != 0) {
        for (unsigned int k = 0; k < count; k++) {
            Owner* o = entries[k].owner;
            o->v8(source->v3(o->v7()));
            Entry* e = &entries[k];
            unsigned int n = (unsigned int)(e->end - e->begin);
            for (unsigned int i = 0; i < n; i++) {
                Child* c = e->begin[i];
                if (c != 0)
                    c->v6(0, 1);
            }
            e->owner->v6();
            o->v8(source->v4(o->v7()));
        }
    } else {
        for (unsigned int k = 0; k < count; k++) {
            Entry* e = &entries[k];
            unsigned int n = (unsigned int)(e->end - e->begin);
            for (unsigned int i = 0; i < n; i++) {
                Child* c = e->begin[i];
                if (c != 0)
                    c->v6(0, 1);
            }
            e->owner->v6();
        }
    }
}

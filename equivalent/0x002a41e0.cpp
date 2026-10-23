// STATUS: equivalent (tools/equiv.py level 3: 19720 inputs, branch coverage 24/24)
// FUN_002a41e0 @ 0x002a41e0
class Owner_2a41e0 {
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
class Child_2a41e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b);
};
class Source_2a41e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int a);
    virtual int v4(int a);
};
struct Entry_2a41e0 {
    Owner_2a41e0* owner;
    Child_2a41e0** begin;
    Child_2a41e0** end;
    Child_2a41e0** cap;
};
#if defined(__clang__)
typedef int (__fastcall *Fn0)(void*, int);
typedef void (__fastcall *Fn1)(void*, int, int);
typedef int (__fastcall *Fn1r)(void*, int, int);
#endif
class Group_2a41e0;
class Parent_2a41e0 {
public:
    void FUN_0029b750(Group_2a41e0* g, int zero, int arg);
};
class Group_2a41e0 {
public:
    char pad0[0x10];
    Source_2a41e0* source;
    char pad14[0x48 - 0x14];
    Entry_2a41e0* entries;
    Entry_2a41e0* entriesEnd;
    void FUN_002a41e0(Parent_2a41e0* parent, int arg);
};

void Group_2a41e0::FUN_002a41e0(Parent_2a41e0* parent, int arg)
{
    if (parent != 0) {
        parent->FUN_0029b750(this, 0, arg);
        return;
    }
    unsigned int count = (unsigned int)(entriesEnd - entries);
    if (source != 0) {
        for (unsigned int k = 0; k < count; k++) {
            Owner_2a41e0* o = entries[k].owner;
#if defined(__clang__)
            {
                // the original loads both vptrs before the first call and reads the slots after it
                void** ovt = *(void***)o;
                Source_2a41e0* s = source;
                void** svt = *(void***)s;
                int a = ((Fn0)ovt[7])(o, 0);
                int b = ((Fn1r)svt[3])(s, 0, a);
                ((Fn1)ovt[8])(o, 0, b);
            }
#else
            o->v8(source->v3(o->v7()));
#endif
            Entry_2a41e0* e = &entries[k];
            unsigned int n = (unsigned int)(e->end - e->begin);
            for (unsigned int i = 0; i < n; i++) {
                Child_2a41e0* c = e->begin[i];
                if (c != 0)
                    c->v6(0, 1);
            }
            e->owner->v6();
#if defined(__clang__)
            {
                // the original loads both vptrs before the first call and reads the slots after it
                void** ovt = *(void***)o;
                Source_2a41e0* s = source;
                void** svt = *(void***)s;
                int a = ((Fn0)ovt[7])(o, 0);
                int b = ((Fn1r)svt[4])(s, 0, a);
                ((Fn1)ovt[8])(o, 0, b);
            }
#else
            o->v8(source->v4(o->v7()));
#endif
        }
    } else {
        for (unsigned int k = 0; k < count; k++) {
            Entry_2a41e0* e = &entries[k];
            unsigned int n = (unsigned int)(e->end - e->begin);
            for (unsigned int i = 0; i < n; i++) {
                Child_2a41e0* c = e->begin[i];
                if (c != 0)
                    c->v6(0, 1);
            }
            e->owner->v6();
        }
    }
}

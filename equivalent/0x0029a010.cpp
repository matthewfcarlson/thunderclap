// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/30)
// FUN_0029a010 @ 0x0029a010
void *__cdecl FUN_0008d690(unsigned int size);

namespace pure3d {
class CompositeDrawable;
}

struct Peer_29a010 {
    char pad00[0x44];
    pure3d::CompositeDrawable *owner;
};

struct ChildEntry {
    int a;
    int b;
    Peer_29a010 *item;
};

struct Children_29a010 {
    virtual void c0();
    char pad04[0x3c - 4];
    ChildEntry *begin;
    ChildEntry *end;
    Children_29a010 *FUN_00299da0(Children_29a010 *src);
    void FUN_00298870();
};

struct Clock_29a010 {
    void *FUN_002842f0();
};

struct Sink4c {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Sink4c *s4();
    void FUN_00288080(Clock_29a010 *clock);
};

struct Sink50 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Sink50 *s4();
    void FUN_002a8310(pure3d::CompositeDrawable *cd);
};

class __declspec(novtable) DrawableBase_29a010 {
public:
    virtual void b0();
    char pad04[0x3c];
    void FUN_002a3530(const DrawableBase_29a010 *src);
    DrawableBase_29a010(const DrawableBase_29a010 &src) { FUN_002a3530(&src); }
};

namespace pure3d {
class CompositeDrawable : public DrawableBase_29a010 {
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void hulk_slot_vfunc_10(void *clock); void vfunc_10(void *clock);
    virtual void vfunc_11();
    virtual void vfunc_12();
    Clock_29a010 *clock;
    Children_29a010 *children;
    void *f48;
    Sink4c *sink4c;
    Sink50 *sink50;
    void FUN_002998d0(int v);
    CompositeDrawable(const CompositeDrawable &src);
};
}

pure3d::CompositeDrawable::CompositeDrawable(const CompositeDrawable &src)
    : DrawableBase_29a010(src)
{
    clock = 0;
    children = 0;
    f48 = 0;
    sink4c = 0;
    sink50 = 0;

    if (src.children != 0) {
        void *mem = FUN_0008d690(0x48);
        Children_29a010 *c = 0;
        if (mem)
            c = ((Children_29a010 *)mem)->FUN_00299da0(src.children);
        children = c;
        children->c0();
        children->FUN_00298870();
        unsigned char n = (unsigned char)(children->end - children->begin);
        if (n != 0) {
            unsigned char i = 0;
            do {
                Peer_29a010 *p = children->begin[i].item;
                if (p != 0)
                    p->owner = this;
                i++;
                n = (unsigned char)(children->end - children->begin);
            } while (i < n);
        }
    }
    if (src.clock != 0)
        vfunc_10(src.clock->FUN_002842f0());

    if (src.sink4c != 0) {
        Sink4c *s = src.sink4c->s4();
        if (s)
            s->s0();
        if (sink4c)
            sink4c->s1();
        sink4c = s;
        if (s)
            s->FUN_00288080(clock);
    }
    if (src.sink50 != 0) {
        Sink50 *s = src.sink50->s4();
        if (s)
            s->s0();
        if (sink50)
            sink50->s1();
        sink50 = s;
        if (s)
            s->FUN_002a8310(this);
    }
    if (src.f48 != 0)
        FUN_002998d0(0);
}

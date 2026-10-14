// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 8/8)
// pure3d::CompositeDrawable::vfunc_13 @ 0x00299010
class Ref {
public:
    virtual void AddRef();
    virtual void Release();
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
    virtual void v11();
    virtual void v12();
    virtual void v13(Ref *r);
};
struct Elem { int a; int b; Child *c; };
struct Impl { char pad[0x3c]; Elem *begin; Elem *end; };

class CompositeDrawable {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13(Ref *r);
    virtual void vfunc_14();
    char pad04[0xc];
    Ref *ref10;
    char pad14[0x44 - 0x14];
    Impl *impl;
};

void CompositeDrawable::vfunc_13(Ref *r)
{
    if (r != 0)
        r->AddRef();
    if (ref10 != 0)
        ref10->Release();
    ref10 = r;
    unsigned int count = (unsigned char)(impl->end - impl->begin);
    for (unsigned int i = 0; i < count; i++)
        impl->begin[i].c->v13(r);
}

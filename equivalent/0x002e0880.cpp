// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_002e0880 @ 0x002e0880
void *FUN_0008d690(unsigned int size);

struct Vec3 { float x, y, z; };

class RefObj {
public:
    virtual void AddRef();
    virtual void Release();
};

class Sub : public RefObj {
public:
    char pad04[0x2c];
    Sub *FUN_002c84a0(Sub *other);
};

class Provider {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual RefObj *v4();
};

namespace pure3d {

class __declspec(novtable) DrawablePrimitive {
public:
    virtual void v0();
    char pad04[0xc];
    void *f10;
    Vec3 bmin;
    Vec3 bmax;
    float plane[4];
    char pad3c[4];
    RefObj *obj40;
    int f44;
    int f48;
    int f4c;
    int f50;
    char pad54[4];
    Provider *prov58;
    Sub *sub5c;
    void FUN_002a5060();
    void *FUN_002a50b0();
    DrawablePrimitive(int a, int b)
    {
        FUN_002a5060();
        obj40 = 0;
        f44 = 0;
        f48 = a;
        f4c = b;
        f50 = -1;
        prov58 = 0;
        sub5c = 0;
    }
};

class VertexAnimPrimGroup : public DrawablePrimitive {
public:
    VertexAnimPrimGroup(const VertexAnimPrimGroup &src);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual RefObj *v7();

};

VertexAnimPrimGroup::VertexAnimPrimGroup(const VertexAnimPrimGroup &src) : DrawablePrimitive(src.f48, src.f4c)
{
    f10 = ((DrawablePrimitive &)src).FUN_002a50b0();
    bmin = src.bmin;
    bmax = src.bmax;
    plane[0] = src.plane[0];
    plane[1] = src.plane[1];
    plane[2] = src.plane[2];
    plane[3] = src.plane[3];
    f44 = src.f44;

    RefObj *o = ((VertexAnimPrimGroup &)src).v7();
    if (o)
        o->AddRef();
    if (obj40)
        obj40->Release();
    obj40 = o;

    RefObj *p = src.prov58->v4();
    if (p)
        p->AddRef();
    if (prov58)
        ((RefObj *)prov58)->Release();
    prov58 = (Provider *)p;

    if (src.sub5c) {
        Sub *mem = (Sub *)FUN_0008d690(0x30);
        Sub *s;
        if (mem)
            s = mem->FUN_002c84a0(src.sub5c);
        else
            s = 0;
        sub5c = s;
        s->AddRef();
    }
    f50 = src.f50;
}

}

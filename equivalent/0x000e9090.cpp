// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000e9090 @ 0x000e9090
struct Vec2f { float x, y, z; };
class Ref_e9090 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Host_e9090;
class Source_e9090 {
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
    virtual void v15(Vec2f *out, Host_e9090 *h);
};
void __cdecl FUN_000f69e0(Ref_e9090 *r, Vec2f *out);

class Host_e9090 {
public:
    char pad0[0x14];
    Source_e9090 *src;
    char pad1[0x50 - 0x18];
    Ref_e9090 *cur;
    float f54;
    float f58;
    float f5c;
    void FUN_000e9090(Ref_e9090 *r);
};

struct Frame_e9090 {
    Vec2f a;
    Vec2f b;
};

void Host_e9090::FUN_000e9090(Ref_e9090 *r)
{
    Frame_e9090 f;
    if (r != 0)
        r->AddRef();
    if (cur != 0)
        cur->Release();
    cur = r;
    if (r != 0) {
        FUN_000f69e0(r, &f.b);
        src->v15(&f.a, this);
        f5c = 1.0f;
        f54 = f.a.x / f.b.x;
        f58 = f.a.y / f.b.y;
    }
}

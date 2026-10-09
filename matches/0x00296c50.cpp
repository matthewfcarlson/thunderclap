class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
class Scenegraph {
  public:
    char pad[0x10];
    Ref* a;
    char pad2[0x2c];
    Ref* b;
    void vfunc_14();
};
struct Callback {
    void* vt;
    Ref* result;
};
extern void FUN_00296220(Ref*, Callback*);
void Scenegraph::vfunc_14() {
    if (a) {
        a->Release();
        a = 0;
    }
    if (b) {
        Callback c;
        c.vt = (void*)0x42d330;
        c.result = 0;
        FUN_00296220(b, &c);
        c.vt = (void*)0x42d330;
        if (c.result)
            ((class Ref*)c.result)->Release();
    }
}
extern "C" char DAT_0042d330[];
class Ref_296c50 {
  public:
    virtual void f0();
    virtual void Release();
};
class Scenegraph {
  public:
    char pad[0x10];
    Ref_296c50* a;
    char pad2[0x2c];
    Ref_296c50* b;
    void vfunc_14();
};
struct Callback_296c50 {
    void* vt;
    Ref_296c50* result;
};
extern void FUN_00296220(Ref_296c50*, Callback_296c50*);
void Scenegraph::vfunc_14() {
    if (a) {
        a->Release();
        a = 0;
    }
    if (b) {
        Callback_296c50 c;
        c.vt = (void*)((int)DAT_0042d330);
        c.result = 0;
        FUN_00296220(b, &c);
        c.vt = (void*)((int)DAT_0042d330);
        if (c.result)
            ((class Ref_296c50*)c.result)->Release();
    }
}
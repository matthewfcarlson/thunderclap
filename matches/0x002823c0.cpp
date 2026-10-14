class Thing_2823c0 {
  public:
    virtual void f();
    virtual void Release();
};
class Obj_2823c0 {
  public:
    char pad[0x20];
    Thing_2823c0* a;
    char pad2[8];
    Thing_2823c0* b;
    char pad3[0x24];
    Thing_2823c0* c;
    void Clear();
};
void Obj_2823c0::Clear() {
    if (b) {
        b->Release();
        b = 0;
    }
    if (a) {
        a->Release();
        a = 0;
    }
    if (c) {
        c->Release();
        c = 0;
    }
}
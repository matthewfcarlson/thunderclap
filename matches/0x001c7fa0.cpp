class Ref_1c7fa0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Slot_1c7fa0 {
  public:
    Ref_1c7fa0* p;
    void Clear() {
        Ref_1c7fa0* q = p;
        if (q) {
            q->Release();
            p = 0;
        }
    }
};
class Obj_1c7fa0 {
    char pad[8];
    Slot_1c7fa0 a;
    Slot_1c7fa0 b;

  public:
    void Set(Ref_1c7fa0* x, Ref_1c7fa0* y);
};
void Obj_1c7fa0::Set(Ref_1c7fa0* x, Ref_1c7fa0* y) {
    if (x) {
        if (a.p)
            a.Clear();
        a.p = x;
        x->AddRef();
    }
    if (y) {
        if (b.p)
            b.Clear();
        b.p = y;
        y->AddRef();
    }
}
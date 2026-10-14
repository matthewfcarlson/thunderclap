extern "C" void _ReadWriteBarrier();
class Ref_29b50 {
  public:
    virtual void Add();
    virtual void Release();
};
class Owner_29b50 {
    char pad[0x344];
    Ref_29b50* a;
    Ref_29b50* b;
    int c;

  public:
    void Set(Ref_29b50* x, Ref_29b50* y, int z);
};
void Owner_29b50::Set(Ref_29b50* x, Ref_29b50* y, int z) {
    if (x)
        x->Add();
    if (a)
        a->Release();
    a = x;
    if (y)
        y->Add();
    if (b)
        b->Release();
    _ReadWriteBarrier();
    b = y;
    c = z;
}
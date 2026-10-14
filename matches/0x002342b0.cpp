class Param;
class Item_2342b0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void Apply(Param*, int);
};
class Param {
  public:
    virtual Item_2342b0* Get(int);
    virtual void V1();
    virtual bool V2(int);
    virtual void V3();
    virtual void V4();
    virtual void V5();
};
bool Param::V2(int arg) {
    int n = 0;
    while (Get(n) != 0)
        ++n;
    --n;
    if (n >= 0) {
        do {
            Item_2342b0* p = Get(n);
            p->Apply(this, arg);
            --n;
        } while (n >= 0);
    }
    return true;
}

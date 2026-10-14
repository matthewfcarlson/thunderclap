class Obj_1c5cf0 {
  public:
    virtual void A();
    virtual void B();
};
void __stdcall Init(int);
class Thing_1c5cf0 {
  public:
    char pad[8];
    Obj_1c5cf0* p;
    int q;
    Thing_1c5cf0* Set(int, Obj_1c5cf0*);
};
Thing_1c5cf0* Thing_1c5cf0::Set(int arg, Obj_1c5cf0* value) {
    Init(arg);
    p = 0;
    if (value) {
        value->A();
        if (p)
            p->B();
    }
    p = value;
    q = 0;
    return this;
}
class Obj {
  public:
    virtual void Vfn0();
    virtual void Vfn1();
    char pad[8];
    int mValue;
    Obj(int v);
    bool Fn(int v);
};

Obj::Obj(int v) : mValue(v) {}
bool Obj::Fn(int v) {
    mValue = v;
    return true;
}

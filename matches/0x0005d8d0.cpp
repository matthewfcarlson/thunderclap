class Obj {
  public:
    virtual void V0();
    virtual void V1();
    char pad[0x28];
    int mValue;
    bool Set(int v);
};
bool Obj::Set(int v) {
    mValue = v;
    return true;
}

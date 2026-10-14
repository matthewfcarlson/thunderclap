class Obj_5d8d0 {
  public:
    virtual void V0();
    virtual void V1();
    char pad[0x28];
    int mValue;
    bool Set(int v);
};
bool Obj_5d8d0::Set(int v) {
    mValue = v;
    return true;
}

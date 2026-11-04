class Obj_47bf0 {
  public:
    virtual void Vfn0();
    virtual void Vfn1();
    char pad[8];
    int mValue;
    Obj_47bf0(int v);
    bool SetAxis_00047bf0(int v);
};

Obj_47bf0::Obj_47bf0(int v) : mValue(v) {}
bool Obj_47bf0::SetAxis_00047bf0(int v) {
    mValue = v;
    return true;
}

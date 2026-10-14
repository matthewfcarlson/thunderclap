class Obj_685c0 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};
bool Obj_685c0::Set(int v) {
    mValue = v;
    return true;
}

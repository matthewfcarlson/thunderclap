class Obj_13e900 {
  public:
    char pad[0x28];
    int mValue;
    bool Set(int v);
};
bool Obj_13e900::Set(int v) {
    mValue = v;
    return true;
}
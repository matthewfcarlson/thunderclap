class Obj_139e80 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};
bool Obj_139e80::Set(int v) {
    mValue = v;
    return true;
}
class Obj_133100 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};
bool Obj_133100::Set(int v) {
    mValue = v;
    return true;
}

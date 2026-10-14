class Obj_47b30 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool Obj_47b30::Set(int v) {
    mValue = v;
    return true;
}

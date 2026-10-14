class Obj_13e860 {
  public:
    char pad[0x14];
    int mValue;
    bool Set(int v);
};

bool Obj_13e860::Set(int v) {
    mValue = v;
    return true;
}

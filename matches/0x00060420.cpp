class Obj_60420 {
  public:
    char pad[0xcc];
    int mValue;
    bool Set(int v);
};

bool Obj_60420::Set(int v) {
    mValue = v;
    return true;
}

class Obj_16f810 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int v);
};

bool Obj_16f810::Set(int v) {
    mValue = v;
    return true;
}
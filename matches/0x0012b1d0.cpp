class Obj_12b1d0 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int x);
};

bool Obj_12b1d0::Set(int x) {
    mValue = x;
    return true;
}

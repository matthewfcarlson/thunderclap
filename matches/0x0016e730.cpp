class Obj_16e730 {
  public:
    char pad[0x10];
    int mVal;
    bool Set(int v);
};

bool Obj_16e730::Set(int v) {
    mVal = v;
    return true;
}

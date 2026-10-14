class Obj_16f3c0 {
  public:
    char pad[0x10];
    int mVal;
    bool Set(int v);
};
bool Obj_16f3c0::Set(int v) {
    mVal = v;
    return true;
}

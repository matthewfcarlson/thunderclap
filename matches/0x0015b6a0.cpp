class Obj_15b6a0 {
  public:
    char pad[0x10];
    int mVal;
    bool Set(int v);
};
bool Obj_15b6a0::Set(int v) {
    mVal = v;
    return true;
}

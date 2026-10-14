class Obj_16f9d0 {
  public:
    char pad[0x28];
    int mVal;
    bool Set(int v);
};
bool Obj_16f9d0::Set(int v) {
    mVal = v;
    return true;
}

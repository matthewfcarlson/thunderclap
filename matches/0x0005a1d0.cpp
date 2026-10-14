class Obj_5a1d0 {
  public:
    char pad[0x54];
    int mVal;
    bool Set(int v);
};
bool Obj_5a1d0::Set(int v) {
    mVal = v;
    return true;
}

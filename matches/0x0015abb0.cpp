class Obj_15abb0 {
  public:
    char pad[0x24];
    int mVal;
    bool Set(int v);
};
bool Obj_15abb0::Set(int v) {
    mVal = v;
    return true;
}

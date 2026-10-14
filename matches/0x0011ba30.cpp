class Obj_11ba30 {
  public:
    char pad[0x24];
    int mVal;
    bool Set(int v);
};
bool Obj_11ba30::Set(int v) {
    mVal = v;
    return true;
}

class Obj_115480 {
  public:
    char pad[0x24];
    int mVal;
    bool Set(int x);
};
bool Obj_115480::Set(int x) {
    mVal = x;
    return true;
}

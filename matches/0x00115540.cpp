class Obj_115540 {
  public:
    char pad[0x24];
    int mVal;
    bool Set(int v);
};
bool Obj_115540::Set(int v) {
    mVal = v;
    return true;
}
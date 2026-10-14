class Obj_13ed00 {
  public:
    char pad[0x18];
    int mVal;
    bool Set(int v);
};
bool Obj_13ed00::Set(int v) {
    mVal = v;
    return true;
}

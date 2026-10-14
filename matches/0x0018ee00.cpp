class Obj_18ee00 {
  public:
    char pad[0x10];
    int mVal;
    bool Set(int v);
};
bool Obj_18ee00::Set(int v) {
    mVal = v;
    return true;
}

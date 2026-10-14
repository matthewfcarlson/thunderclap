class Obj_16f930 {
  public:
    char pad[0xc];
    int mVal;
    bool Set(int v);
};
bool Obj_16f930::Set(int v) {
    mVal = v;
    return true;
}

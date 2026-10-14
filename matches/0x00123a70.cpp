class Obj_123a70 {
  public:
    char pad[0x10];
    int mVal;
    bool Set(int v);
};
bool Obj_123a70::Set(int v) {
    mVal = v;
    return true;
}
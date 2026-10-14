class Obj_6b3e0 {
  public:
    char pad[0x50];
    int mVal;
    bool Set(int v);
};
bool Obj_6b3e0::Set(int v) {
    mVal = v;
    return true;
}

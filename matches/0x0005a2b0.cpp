class Obj_5a2b0 {
  public:
    char pad[0xc];
    int mVal;
    bool Set(int x);
};
bool Obj_5a2b0::Set(int x) {
    mVal = x;
    return true;
}
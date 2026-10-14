class Obj_68b40 {
  public:
    char pad[0xc];
    int mVal;
    bool Set(int v);
};
bool Obj_68b40::Set(int v) {
    mVal = v;
    return true;
}

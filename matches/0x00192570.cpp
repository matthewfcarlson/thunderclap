class Obj_192570 {
  public:
    char pad[0xc];
    int mVal;
    bool Set(int v);
};
bool Obj_192570::Set(int v) {
    mVal = v;
    return true;
}

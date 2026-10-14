class Obj {
  public:
    char pad[0x24];
    int mVal;
    bool Set(int v);
};
bool Obj::Set(int v) {
    mVal = v;
    return true;
}

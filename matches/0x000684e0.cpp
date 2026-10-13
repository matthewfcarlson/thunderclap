class Obj {
  public:
    char pad[0x34];
    int mVal;
    bool Set(int v);
};
bool Obj::Set(int v) {
    mVal = v;
    return true;
}

class Obj {
  public:
    char pad[0xc];
    int mVal;
    bool Set(int x);
};
bool Obj::Set(int x) {
    mVal = x;
    return true;
}

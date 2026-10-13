class Obj {
  public:
    char pad[0xc];
    int mVal;
    bool Fn(int x);
};
bool Obj::Fn(int x) {
    mVal = x;
    return true;
}

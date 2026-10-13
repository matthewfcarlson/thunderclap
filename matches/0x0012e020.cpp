class Obj {
  public:
    char Pad[0xc];
    int mVal;
    bool Fn(int x);
};
bool Obj::Fn(int x) {
    mVal = x;
    return true;
}

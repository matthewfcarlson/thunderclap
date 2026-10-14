class Obj {
  public:
    char m[0x14];
    int mVal;
    bool Fn(int x);
};

bool Obj::Fn(int x) {
    mVal = x;
    return true;
}

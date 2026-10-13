class Obj {
  public:
    char m0[0xc];
    int mVal;
    bool Set(int v);
};

bool Obj::Set(int v) {
    mVal = v;
    return true;
}

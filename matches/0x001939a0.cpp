class Obj {
  public:
    char pad[0x5c];
    int mVal;
    bool mFlag;
    bool Set(int x);
};

bool Obj::Set(int x) {
    mVal = x;
    return true;
}

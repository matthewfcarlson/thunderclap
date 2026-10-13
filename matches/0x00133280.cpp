class Obj {
  public:
    char pad[0x20];
    int mVal;
    bool Set(int x);
};

bool Obj::Set(int x) {
    mVal = x;
    return true;
}

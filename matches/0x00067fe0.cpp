class Obj {
  public:
    char pad[12];
    int mVal;
    bool Set(int x);
};

bool Obj::Set(int x) {
    mVal = x;
    return true;
}

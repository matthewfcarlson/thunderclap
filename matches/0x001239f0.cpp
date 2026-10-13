class Obj {
  public:
    char pad[0x18];
    int mVal;
    bool Fn(int x);
};

bool Obj::Fn(int x) {
    mVal = x;
    return true;
}

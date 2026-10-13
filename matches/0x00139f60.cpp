class Obj {
  public:
    bool Set(int x);
    char pad[0x38];
    int mX;
};

bool Obj::Set(int x) {
    mX = x;
    return true;
}

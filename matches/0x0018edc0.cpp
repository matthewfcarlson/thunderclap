class Obj {
  public:
    char pad[0x40];
    int mValue;
    bool Set(int x);
};

bool Obj::Set(int x) {
    mValue = x;
    return true;
}

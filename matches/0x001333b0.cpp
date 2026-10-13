class Obj {
  public:
    char pad[0x20];
    int mValue;
    bool Set(int x);
};

bool Obj::Set(int x) {
    mValue = x;
    return true;
}
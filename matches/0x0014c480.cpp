class Obj {
  public:
    char pad[0x10];
    int mField;
    bool Set(int x);
};

bool Obj::Set(int x) {
    mField = x;
    return true;
}

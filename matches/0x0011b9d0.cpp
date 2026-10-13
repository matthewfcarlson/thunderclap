class Obj {
  public:
    char pad[0x18];
    int m18;
    bool Set(int x);
};

bool Obj::Set(int x) {
    m18 = x;
    return true;
}

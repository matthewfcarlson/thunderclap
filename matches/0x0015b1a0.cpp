class Obj {
  public:
    char pad[0x90];
    int m90;
    bool Set(int x);
};

bool Obj::Set(int x) {
    m90 = x;
    return true;
}

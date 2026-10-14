class Obj {
  public:
    char pad[0x134];
    int m134;
    bool Set(int x);
};

bool Obj::Set(int x) {
    m134 = x;
    return true;
}
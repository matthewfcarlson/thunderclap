class Obj {
  public:
    char pad[0x14];
    int m14;
    bool Set(int x);
};

bool Obj::Set(int x) {
    m14 = x;
    return true;
}

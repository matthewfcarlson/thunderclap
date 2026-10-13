class Obj {
  public:
    char pad[0x34];
    int m34;
    bool Set(int x);
};

bool Obj::Set(int x) {
    m34 = x;
    return true;
}

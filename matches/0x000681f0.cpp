class Obj {
  public:
    char pad[0x34];
    int m34;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m34 = v;
    return true;
}

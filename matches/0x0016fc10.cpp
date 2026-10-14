class Obj {
  public:
    char pad[0x40];
    int m40;
    bool Set(int v);
};

bool Obj::Set(int v) {
    m40 = v;
    return true;
}
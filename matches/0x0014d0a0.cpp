class Obj {
  public:
    char pad[0x2c];
    int m2c;
    bool Set(int x);
};

bool Obj::Set(int x) {
    m2c = x;
    return true;
}

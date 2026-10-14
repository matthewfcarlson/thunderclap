class Obj {
  public:
    char pad[0x14];
    int m;
    bool Set(int x);
};

bool Obj::Set(int x) {
    m = x;
    return true;
}
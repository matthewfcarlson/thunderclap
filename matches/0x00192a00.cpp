class Obj {
  public:
    char pad[0x64];
    int m64;
    bool Set(int x);
};
bool Obj::Set(int x) {
    m64 = x;
    return true;
}

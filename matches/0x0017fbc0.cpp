class Obj {
  public:
    char pad[0x60];
    int m60;
    bool Set(int x);
};
bool Obj::Set(int x) {
    m60 = x;
    return true;
}

class Obj {
  public:
    char pad[0x10];
    int m10;
    bool Set(int x);
};
bool Obj::Set(int x) {
    m10 = x;
    return true;
}

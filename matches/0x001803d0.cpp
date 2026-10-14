class Obj {
  public:
    char pad[0x14];
    int m14;
    bool Set(int a);
};
bool Obj::Set(int a) {
    m14 = a;
    return true;
}

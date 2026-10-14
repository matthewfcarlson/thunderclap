class Obj {
  public:
    char pad[0x30];
    int m30;
    bool Set(int a);
};
bool Obj::Set(int a) {
    m30 = a;
    return true;
}

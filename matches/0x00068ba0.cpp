class Obj {
  public:
    char pad[0x10];
    int m10;
    bool Set10(int v);
};
bool Obj::Set10(int v) {
    m10 = v;
    return true;
}

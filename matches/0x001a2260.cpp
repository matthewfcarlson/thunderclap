class Obj {
  public:
    char pad[0x3c];
    int m3c;
    bool Set(int x);
};
bool Obj::Set(int x) {
    m3c = x;
    return true;
}

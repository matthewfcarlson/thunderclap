class Obj {
  public:
    char pad[0x1c];
    int m;
    bool Set(int x);
};
bool Obj::Set(int x) {
    m = x;
    return true;
}

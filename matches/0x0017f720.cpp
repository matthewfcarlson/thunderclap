class Obj {
  public:
    char pad[0xc];
    int m12;
    bool Set(int v);
};
bool Obj::Set(int v) {
    m12 = v;
    return true;
}

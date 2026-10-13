class Obj {
  public:
    char pad[12];
    int m12;
    bool Set(int v);
};
bool Obj::Set(int v) {
    m12 = v;
    return true;
}

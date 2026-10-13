class Obj {
  public:
    char pad[0x2c];
    int m2c;
    bool Set(int v);
};
bool Obj::Set(int v) {
    m2c = v;
    return true;
}

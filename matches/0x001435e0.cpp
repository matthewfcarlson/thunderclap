class Obj {
  public:
    char pad[0x50];
    int m50;
    bool Set(int v);
};
bool Obj::Set(int v) {
    m50 = v;
    return true;
}

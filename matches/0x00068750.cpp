class Obj {
  public:
    char pad[0x98];
    int m98;
    bool Set(int v);
};
bool Obj::Set(int v) {
    m98 = v;
    return true;
}
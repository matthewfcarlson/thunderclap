class Obj {
  public:
    char pad[0x174];
    int m174;
    bool Set(int v);
};
bool Obj::Set(int v) {
    m174 = v;
    return true;
}

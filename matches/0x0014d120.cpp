class Obj {
  public:
    char pad[0x14];
    int value;
    bool Set(int v);
};
bool Obj::Set(int v) {
    value = v;
    return true;
}

class Obj {
  public:
    char pad[0x2c];
    int value;
    bool Set(int v);
};
bool Obj::Set(int v) {
    value = v;
    return true;
}
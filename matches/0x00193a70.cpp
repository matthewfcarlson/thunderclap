class Obj {
  public:
    bool Set(int v);
    char pad[0x74];
    int value;
};
bool Obj::Set(int v) {
    value = v;
    return true;
}

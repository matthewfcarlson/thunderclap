class Obj {
  public:
    char pad[0x24];
    int m24;
    bool Set(int value);
};
bool Obj::Set(int value) {
    m24 = value;
    return true;
}

class Obj {
  public:
    char pad[0x48];
    int field;
    char flag;
    bool Set(int value);
};
bool Obj::Set(int value) {
    field = value;
    return true;
}
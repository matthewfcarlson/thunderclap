class Obj {
  public:
    char pad[0x48];
    char flag;
    bool Set(char v);
};
bool Obj::Set(char v) {
    flag = v;
    return true;
}

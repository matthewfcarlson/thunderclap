class Obj {
  public:
    char pad[0x19];
    char flag;
    bool SetFlag(char v);
};
bool Obj::SetFlag(char v) {
    flag = v;
    return true;
}
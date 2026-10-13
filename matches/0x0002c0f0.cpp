class Obj {
  public:
    char pad[0x50];
    char flag;
    char GetFlag();
};
char Obj::GetFlag() {
    return flag;
}

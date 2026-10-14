class Obj {
  public:
    char pad[0x30];
    char m30;
    char Set(char v);
};
char Obj::Set(char v) {
    m30 = v;
    return 1;
}
class Obj {
  public:
    char Set(char v);
    char pad[0x51];
    char value;
};
char Obj::Set(char v) {
    value = v;
    return 1;
}

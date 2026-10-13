class Obj {
  public:
    char pad[0x14];
    char value;
    char Set(char v);
};
char Obj::Set(char v) {
    value = v;
    return 1;
}

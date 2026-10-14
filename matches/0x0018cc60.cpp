class Obj {
  public:
    char pad[0x24];
    char m24;
    char Set(char v);
};

char Obj::Set(char v) {
    m24 = v;
    return 1;
}

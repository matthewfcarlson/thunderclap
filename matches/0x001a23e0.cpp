class Obj {
  public:
    char pad[0x68];
    char m68;
    char Set(char v);
};

char Obj::Set(char v) {
    m68 = v;
    return 1;
}

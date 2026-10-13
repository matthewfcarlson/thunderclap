class Obj {
  public:
    char pad[0x38];
    char m38;
    char Set(char v);
};

char Obj::Set(char v) {
    m38 = v;
    return 1;
}
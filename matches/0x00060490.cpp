class Obj {
  public:
    char pad[0x50];
    char m50;
    char Set(char c);
};

char Obj::Set(char c) {
    m50 = c;
    return 1;
}

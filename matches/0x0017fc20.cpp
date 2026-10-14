class Obj {
  public:
    char Set(char x);
    char pad[0x80];
    char m80;
};

char Obj::Set(char x) {
    m80 = x;
    return 1;
}

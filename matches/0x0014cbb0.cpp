class Obj {
  public:
    char m0[0x28];
    char m28;
    char Set(char c);
};
char Obj::Set(char c) {
    m28 = c;
    return 1;
}

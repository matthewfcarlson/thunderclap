class Obj {
  public:
    char m0[0x14];
    char Set(char v);
};
char Obj::Set(char v) {
    m0[0x14] = v;
    return 1;
}

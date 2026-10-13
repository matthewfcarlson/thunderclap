class Obj {
  public:
    char m0[32];
    char m20;
    char Set(char x);
};
char Obj::Set(char x) {
    m20 = x;
    return 1;
}
class Obj {
  public:
    char m0[0x14];
    char m14;
    char Fn(char x);
};
char Obj::Fn(char x) {
    m14 = x;
    return 1;
}

class Obj {
  public:
    char m[0x29];
    char Fn(char a);
};
char Obj::Fn(char a) {
    m[0x29] = a;
    return 1;
}

class Obj {
  public:
    char F(char value);
    char m[0x139];
};
char Obj::F(char value) {
    m[0x139] = value;
    return 1;
}

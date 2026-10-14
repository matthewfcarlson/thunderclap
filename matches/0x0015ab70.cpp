class Obj {
  public:
    char m[0x1c];
    char Fn(char c);
};
char Obj::Fn(char c) {
    m[0x1c] = c;
    return 1;
}

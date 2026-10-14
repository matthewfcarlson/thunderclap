class Obj {
  public:
    char pad[0x96];
    char m96;
    char Fn(char x);
};

char Obj::Fn(char x) {
    m96 = x;
    return 1;
}
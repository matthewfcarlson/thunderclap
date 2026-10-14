class Obj {
  public:
    char pad[0xd9];
    char m;
    char Fn(char x);
};

char Obj::Fn(char x) {
    m = x;
    return 1;
}

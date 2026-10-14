class Obj {
  public:
    char pad[0xd];
    char mD;
    char Fn(char c);
};
char Obj::Fn(char c) {
    mD = c;
    return 1;
}
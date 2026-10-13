class Obj {
  public:
    char pad[0x10];
    int field;
    char Fn(int x);
};
char Obj::Fn(int x) {
    field = x;
    return 1;
}

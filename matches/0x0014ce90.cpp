class Obj {
  public:
    char pad[0x24];
    int m24;
    char Fn(int a);
};
char Obj::Fn(int a) {
    m24 = a;
    return 1;
}

class Obj {
  public:
    char Fn(int a);
    char pad[0x18];
    int m18;
};

char Obj::Fn(int a) {
    m18 = a;
    return 1;
}

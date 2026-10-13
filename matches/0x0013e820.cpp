class Obj {
  public:
    char pad[0x10];
    int m10;
    char Fn(int a);
};

char Obj::Fn(int a) {
    m10 = a;
    return 1;
}

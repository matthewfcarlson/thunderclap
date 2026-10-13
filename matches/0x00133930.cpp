class Obj {
  public:
    char f(int a);
    char pad[0x38];
    int m38;
};

char Obj::f(int a) {
    m38 = a;
    return 1;
}
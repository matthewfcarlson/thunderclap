class Obj {
  public:
    char f(int x);
    char pad[0x1c];
    int m1c;
};
char Obj::f(int x) {
    m1c = x;
    return 1;
}
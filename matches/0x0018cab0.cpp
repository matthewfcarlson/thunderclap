class Obj {
  public:
    char f1(int a);
    char pad[0xc];
    int mValue;
};
char Obj::f1(int a) {
    mValue = a;
    return 1;
}
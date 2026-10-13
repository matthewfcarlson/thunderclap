class Obj {
  public:
    char Get(int a);
    char pad[0x18];
    int m18;
};
char Obj::Get(int a) {
    m18 = a;
    return 1;
}

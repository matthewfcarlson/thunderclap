class Obj {
  public:
    char Set(int a);
    char pad[0x18];
    int m18;
};
char Obj::Set(int a) {
    m18 = a;
    return 1;
}

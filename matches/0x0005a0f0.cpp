class Obj {
  public:
    char pad[0x70];
    int m70;
    char Set(int x);
};
char Obj::Set(int x) {
    m70 = x;
    return 1;
}

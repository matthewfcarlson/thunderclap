class Obj {
  public:
    char pad[0x14];
    int m14;
    char Set(int a);
};
char Obj::Set(int a) {
    m14 = a;
    return 1;
}

class Obj {
  public:
    char pad[0x38];
    int m38;
    char Set(int a);
};
char Obj::Set(int a) {
    m38 = a;
    return 1;
}

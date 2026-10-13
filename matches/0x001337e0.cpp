class Obj {
  public:
    char pad[0x38];
    int m38;
    char Set(int x);
};
char Obj::Set(int x) {
    m38 = x;
    return 1;
}
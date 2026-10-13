class Obj {
  public:
    char pad[0x50];
    int m50;
    char Set(int x);
};
char Obj::Set(int x) {
    m50 = x;
    return 1;
}

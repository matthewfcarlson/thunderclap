class Obj {
  public:
    char Set(int x);
    char pad[0x24];
    int m24;
};

char Obj::Set(int x) {
    m24 = x;
    return 1;
}

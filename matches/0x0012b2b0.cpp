class Obj {
  public:
    char Set(int x);
    char pad[0x14];
    int m14;
};

char Obj::Set(int x) {
    m14 = x;
    return 1;
}

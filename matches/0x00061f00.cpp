class Obj {
  public:
    char pad[0x34];
    int m34;
    char Set(int x);
};

char Obj::Set(int x) {
    m34 = x;
    return 1;
}
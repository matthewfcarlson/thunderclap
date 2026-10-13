class Obj {
  public:
    char Set(int x);
    char pad[0x33];
    int m34;
};

char Obj::Set(int x) {
    m34 = x;
    return 1;
}

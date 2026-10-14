class Obj {
  public:
    char pad[0xc];
    int m;
    char Set(int x);
};

char Obj::Set(int x) {
    m = x;
    return 1;
}

class Obj {
  public:
    char pad[12];
    int m;
    char Set(int x);
};

char Obj::Set(int x) {
    m = x;
    return 1;
}
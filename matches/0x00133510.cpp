class Obj {
  public:
    char Set(int v);
    char pad[24];
    int m18;
};

char Obj::Set(int v) {
    m18 = v;
    return 1;
}

class Obj {
  public:
    char pad[0x154];
    int m154;
    char Set(int v);
};

char Obj::Set(int v) {
    m154 = v;
    return 1;
}

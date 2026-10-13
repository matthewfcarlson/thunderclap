class Obj {
  public:
    char pad[0x14];
    int m14;
    char Set(int v);
};

char Obj::Set(int v) {
    m14 = v;
    return 1;
}

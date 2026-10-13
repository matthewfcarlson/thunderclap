class Obj {
  public:
    char Set(int v);
    char pad[0x13];
    int m14;
};

char Obj::Set(int v) {
    m14 = v;
    return 1;
}

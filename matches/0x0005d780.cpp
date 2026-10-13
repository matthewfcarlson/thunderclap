class Obj {
  public:
    char pad[0x40];
    int m40;
    char Set(int v);
};

char Obj::Set(int v) {
    m40 = v;
    return 1;
}

class Obj {
  public:
    char Pad[0x20];
    int m20;
    char Set(int v);
};

char Obj::Set(int v) {
    m20 = v;
    return 1;
}

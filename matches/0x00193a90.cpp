class Obj {
  public:
    char Set(int v);
    char pad[0x78];
    int m78;
};

char Obj::Set(int v) {
    m78 = v;
    return 1;
}

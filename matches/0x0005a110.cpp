class Obj {
  public:
    char pad[0x78];
    int m78;
    char Set(int v);
};

char Obj::Set(int v) {
    m78 = v;
    return 1;
}
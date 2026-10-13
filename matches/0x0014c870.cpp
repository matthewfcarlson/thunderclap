class Obj {
  public:
    char Set(int v);
    char pad[0x28];
    int m28;
};

char Obj::Set(int v) {
    m28 = v;
    return 1;
}

class Obj {
  public:
    char pad[0x18];
    int m18;
    char Set(int v);
};

char Obj::Set(int v) {
    m18 = v;
    return 1;
}

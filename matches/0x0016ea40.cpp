class Foo_16ea40 {
  public:
    char pad[0x10];
    int m;
    char Set(int v);
};

char Foo_16ea40::Set(int v) {
    m = v;
    return 1;
}

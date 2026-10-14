class Foo {
  public:
    char pad[0x10];
    int m;
    char Set(int v);
};

char Foo::Set(int v) {
    m = v;
    return 1;
}

class Foo {
  public:
    char Set(char x);
    char pad[0x18];
    char m18;
};

char Foo::Set(char x) {
    m18 = x;
    return 1;
}
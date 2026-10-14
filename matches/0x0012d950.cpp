class Foo_12d950 {
  public:
    char Set(char x);
    char pad[0x18];
    char m18;
};

char Foo_12d950::Set(char x) {
    m18 = x;
    return 1;
}
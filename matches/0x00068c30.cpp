class X {
  public:
    char pad[0x28];
    int m28;
    char Fn(int a);
};

char X::Fn(int a) {
    m28 = a;
    return 1;
}

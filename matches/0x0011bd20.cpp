class A {
  public:
    char Set(int v);
    char pad[0x33];
    int m34;
};
char A::Set(int v) {
    m34 = v;
    return 1;
}

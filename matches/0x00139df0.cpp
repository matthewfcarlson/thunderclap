class A {
  public:
    char pad[0x28];
    int m28;
    char Set(int x);
};
char A::Set(int x) {
    m28 = x;
    return 1;
}

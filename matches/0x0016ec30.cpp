class X {
  public:
    char pad[0x44];
    int m44;
    char Set(int a);
};

char X::Set(int a) {
    m44 = a;
    return 1;
}

class A {
  public:
    virtual void v0();
    char pad[0x10 - 4];
    int m10;
    char b14;
    char Set(int x);
};

char A::Set(int x) {
    m10 = x;
    char r = 1;
    return r;
}

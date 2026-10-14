class A_165430 {
  public:
    virtual void v0();
    char pad[0x10 - 4];
    int m10;
    char b14;
    char Set(int x);
};

char A_165430::Set(int x) {
    m10 = x;
    char r = 1;
    return r;
}

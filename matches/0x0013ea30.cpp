class A {
  public:
    virtual void V();
    char pad[12];
    int m;
    unsigned char Set(int x);
};
unsigned char A::Set(int x) {
    m = x;
    return 1;
}

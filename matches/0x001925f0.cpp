class X {
  public:
    virtual void V();
    char pad[0x1c];
    int m20;
    char Set(int a);
};
char X::Set(int a) {
    m20 = a;
    return 1;
}

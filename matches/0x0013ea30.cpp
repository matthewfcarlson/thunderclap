class A_13ea30 {
  public:
    virtual void V();
    char pad[12];
    int m;
    unsigned char Set(int x);
};
unsigned char A_13ea30::Set(int x) {
    m = x;
    return 1;
}

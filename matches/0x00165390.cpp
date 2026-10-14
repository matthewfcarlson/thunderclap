class C {
  public:
    char pad[0x10];
    int m10;
    char Set(int v);
};

char C::Set(int v) {
    m10 = v;
    return 1;
}

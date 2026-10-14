class C_15a910 {
  public:
    char pad[0x18];
    int m;
    char Set(int v);
};

char C_15a910::Set(int v) {
    m = v;
    return 1;
}

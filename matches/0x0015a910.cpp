class C {
  public:
    char pad[0x18];
    int m;
    char Set(int v);
};

char C::Set(int v) {
    m = v;
    return 1;
}

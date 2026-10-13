class C {
  public:
    char pad[0x4c];
    unsigned int m;
    char Set(unsigned int v);
};

char C::Set(unsigned int v) {
    m = v;
    return 1;
}

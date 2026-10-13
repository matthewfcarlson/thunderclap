class O {
    char pad[0x10];
    int m10;

  public:
    char Set(int v);
};

char O::Set(int v) {
    m10 = v;
    return 1;
}

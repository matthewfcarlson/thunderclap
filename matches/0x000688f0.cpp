class O {
  public:
    char Set(int v);
    int m4;
    int m8;
    int pad;
    int m1c;
};

char O::Set(int v) {
    m1c = v;
    return 1;
}

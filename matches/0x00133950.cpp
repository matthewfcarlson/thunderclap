class O {
  public:
    char pad[0x3c];
    int mVal;
    char Set(int v);
};

char O::Set(int v) {
    char r = 1;
    int* q = &mVal;
    *q = v;
    return r;
}

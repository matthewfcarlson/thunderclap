class X {
  public:
    char m[0xc];
    int value;
    char Set(int v);
};

char X::Set(int v) {
    value = v;
    return 1;
}

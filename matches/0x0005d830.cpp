class C_5d830 {
  public:
    char pad[0x3c];
    int value;
    char Set(int x);
};

char C_5d830::Set(int x) {
    value = x;
    return 1;
}

class X {
  public:
    char pad[0x44];
    int m;
    char Set(int arg);
};

char X::Set(int arg) {
    m = arg;
    return 1;
}

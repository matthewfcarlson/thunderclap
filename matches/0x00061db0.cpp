class X_61db0 {
  public:
    char pad[0x44];
    int m;
    char Set(int arg);
};

char X_61db0::Set(int arg) {
    m = arg;
    return 1;
}

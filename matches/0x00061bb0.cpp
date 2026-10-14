class X_61bb0 {
  public:
    char pad[0x28];
    int m;
    char Set(int);
};

char X_61bb0::Set(int v) {
    m = v;
    return 1;
}

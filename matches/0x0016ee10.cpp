class X_16ee10 {
  public:
    char pad[0x14];
    int value;
    char Set(int v);
};

char X_16ee10::Set(int v) {
    value = v;
    return 1;
}

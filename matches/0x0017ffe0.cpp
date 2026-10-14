class X_17ffe0 {
  public:
    char pad[0x44];
    int mValue;
    char Set(int value);
};

char X_17ffe0::Set(int value) {
    mValue = value;
    return 1;
}

class X_14cca0 {
  public:
    char pad[0x44];
    char m44;
    char Set(char v);
};

char X_14cca0::Set(char v) {
    m44 = v;
    return 1;
}

class X_123730 {
    char pad[0x16];

  public:
    char Set(char c);
};
char X_123730::Set(char c) {
    ((char*)this)[0x16] = c;
    return 1;
}
// cl-flags: /O2
class X_1338f0 {
  public:
    char pad[0x30];
    char m30;
    unsigned char Set(char b);
};

unsigned char X_1338f0::Set(char b) {
    m30 = b;
    return 1;
}

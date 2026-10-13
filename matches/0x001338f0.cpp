// cl-flags: /O2
class X {
  public:
    char pad[0x30];
    char m30;
    unsigned char Set(char b);
};

unsigned char X::Set(char b) {
    m30 = b;
    return 1;
}

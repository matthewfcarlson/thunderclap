// cl-flags: /O2

class O {
  public:
    char pad[0x20];
    char m20;
    char Set(char v);
};

char O::Set(char v) {
    m20 = v;
    return 1;
}

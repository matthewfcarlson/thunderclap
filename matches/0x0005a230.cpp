// cl-flags: /O2

class O_5a230 {
  public:
    char pad[0x20];
    char m20;
    char Set(char v);
};

char O_5a230::Set(char v) {
    m20 = v;
    return 1;
}

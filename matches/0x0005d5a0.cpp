// cl-flags: /O2
class C_5d5a0 {
  public:
    char Set(int v);
    char pad[0x48];
    int m;
};

char C_5d5a0::Set(int v) {
    m = v;
    return 1;
}

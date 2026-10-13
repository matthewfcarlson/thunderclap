// cl-flags: /O2
class C {
  public:
    char Set(int v);
    char pad[0x48];
    int m;
};

char C::Set(int v) {
    m = v;
    return 1;
}

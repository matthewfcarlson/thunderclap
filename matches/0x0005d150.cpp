struct M {
    int val;
};
class X {
  public:
    char Set(int v);
    char pad[0x18];
    M m;
};

char X::Set(int v) {
    m.val = v;
    return 1;
}

struct M_5d150 {
    int val;
};
class X_5d150 {
  public:
    char Set(int v);
    char pad[0x18];
    M_5d150 m;
};

char X_5d150::Set(int v) {
    m.val = v;
    return 1;
}

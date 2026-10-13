class X {
  public:
    char Set(int v);
    char pad[12];
    int m;
};

char X::Set(int v) {
    *(volatile int*)&m = v;
    return 1;
}

void UseX() {
    X x;
    x.Set(0);
}

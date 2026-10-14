class X_143610 {
  public:
    char Set(int v);
    char pad[12];
    int m;
};

char X_143610::Set(int v) {
    *(volatile int*)&m = v;
    return 1;
}

void UseX() {
    X_143610 x;
    x.Set(0);
}

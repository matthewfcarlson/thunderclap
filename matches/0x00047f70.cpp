class X_47f70 {
  public:
    virtual void f();
    char pad[0x0c];
    int value;
    char Set(int v);
};

char X_47f70::Set(int v) {
    value = v;
    return 1;
}

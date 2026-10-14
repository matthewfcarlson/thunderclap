class X_192b20 {
  public:
    char Set(int v);
    char pad[0xa0];
};

char X_192b20::Set(int v) {
    *(int*)((char*)this + 0xa0) = v;
    return 1;
}

class X_12e130 {
  public:
    char Set(int v);
    char pad[0x18];
};

char X_12e130::Set(int v) {
    *(int*)((char*)this + 0x18) = v;
    return 1;
}

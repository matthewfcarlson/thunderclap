class X_14d000 {
  public:
    char Set(int v);
};

char X_14d000::Set(int v) {
    *(int*)((char*)this + 0x18) = v;
    return 1;
}

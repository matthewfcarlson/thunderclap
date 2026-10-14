class X_16fbf0 {
  public:
    char Set(int v);
};
char X_16fbf0::Set(int v) {
    *(int*)((char*)this + 0x3c) = v;
    return 1;
}

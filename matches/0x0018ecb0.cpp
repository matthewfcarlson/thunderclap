class X_18ecb0 {
  public:
    char Set(int v);
};

char X_18ecb0::Set(int v) {
    *(int*)((char*)this + 0xc) = v;
    return 1;
}
class X_143580 {
  public:
    char Set(int v);
};

char X_143580::Set(int v) {
    *(int*)((char*)this + 0x44) = v;
    return 1;
}

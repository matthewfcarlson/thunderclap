class X {
  public:
    char Set(int v);
};
char X::Set(int v) {
    *(int*)((char*)this + 0x3c) = v;
    return 1;
}

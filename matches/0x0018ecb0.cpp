class X {
  public:
    char Set(int v);
};

char X::Set(int v) {
    *(int*)((char*)this + 0xc) = v;
    return 1;
}
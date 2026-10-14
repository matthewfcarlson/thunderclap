class X {
  public:
    char Set(int v);
};

char X::Set(int v) {
    *(int*)((char*)this + 0x18) = v;
    return 1;
}

class X {
  public:
    char Set(int v);
};

char X::Set(int v) {
    *(int*)((char*)this + 0x44) = v;
    return 1;
}

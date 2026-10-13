class X {
  public:
    char pad[0x10];
    char Set(int v);
};

char X::Set(int v) {
    *(int*)((char*)this + 0x10) = v;
    return 1;
}

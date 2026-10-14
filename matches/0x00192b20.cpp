class X {
  public:
    char Set(int v);
    char pad[0xa0];
};

char X::Set(int v) {
    *(int*)((char*)this + 0xa0) = v;
    return 1;
}

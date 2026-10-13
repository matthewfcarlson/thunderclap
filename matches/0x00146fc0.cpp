class X {
  public:
    char pad[0x44];
    char Set(int v);
};
char X::Set(int v) {
    *(int*)((char*)this + 0x44) = v;
    return 1;
}

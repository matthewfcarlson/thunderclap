class X {
    char pad[0x24];

  public:
    char Set(int a);
};
char X::Set(int a) {
    *(int*)((char*)this + 0x24) = a;
    return 1;
}

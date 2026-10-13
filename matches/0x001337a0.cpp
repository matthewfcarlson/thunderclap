class C {
    char pad[0x30];

  public:
    char Set(int x);
};
char C::Set(int x) {
    *((int*)((char*)this + 0x30)) = x;
    return 1;
}

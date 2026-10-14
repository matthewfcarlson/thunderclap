class C_1337a0 {
    char pad[0x30];

  public:
    char Set(int x);
};
char C_1337a0::Set(int x) {
    *((int*)((char*)this + 0x30)) = x;
    return 1;
}

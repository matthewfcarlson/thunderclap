class C_237270 {
    char pad[0x24];

  public:
    char Set(int x);
};

char C_237270::Set(int x) {
    *(int*)((char*)this + 0x24) = x;
    return 1;
}

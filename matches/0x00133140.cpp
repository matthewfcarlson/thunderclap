class C_133140 {
  public:
    char Set(int x);
    char pad[0x18];
};

char C_133140::Set(int x) {
    *(int*)((char*)this + 0x18) = x;
    return 1;
}
class C_143690 {
    char pad[0x1c];

  public:
    char Set(unsigned int x);
};
char C_143690::Set(unsigned int x) {
    *(unsigned int*)((char*)this + 0x1c) = x;
    return 1;
}

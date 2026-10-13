class C {
    char pad[0x1c];

  public:
    char Set(unsigned int x);
};
char C::Set(unsigned int x) {
    *(unsigned int*)((char*)this + 0x1c) = x;
    return 1;
}

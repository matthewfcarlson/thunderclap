class C {
    char pad[0x24];

  public:
    char Set(int x);
};

char C::Set(int x) {
    *(int*)((char*)this + 0x24) = x;
    return 1;
}

class C {
  public:
    char Set(int x);
    char pad[0x18];
};

char C::Set(int x) {
    *(int*)((char*)this + 0x18) = x;
    return 1;
}
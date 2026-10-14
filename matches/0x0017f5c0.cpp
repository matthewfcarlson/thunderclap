class X {
  public:
    char pad[16];
    char Set(int value);
};

char X::Set(int value) {
    *(int*)((char*)this + 0x10) = value;
    return 1;
}

class X {
  public:
    char pad[0xe];
    char Set(unsigned char c);
};

char X::Set(unsigned char c) {
    *(char*)((char*)this + 0xe) = c;
    return 1;
}

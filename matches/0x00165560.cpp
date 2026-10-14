class X_165560 {
  public:
    char pad[0xe];
    char Set(unsigned char c);
};

char X_165560::Set(unsigned char c) {
    *(char*)((char*)this + 0xe) = c;
    return 1;
}

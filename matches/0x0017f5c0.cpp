class X_17f5c0 {
  public:
    char pad[16];
    char Set(int value);
};

char X_17f5c0::Set(int value) {
    *(int*)((char*)this + 0x10) = value;
    return 1;
}

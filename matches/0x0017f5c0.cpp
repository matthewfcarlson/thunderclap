class X_17f5c0 {
  public:
    char pad[16];
    char SetCompare_0017f5c0(int value);
};

char X_17f5c0::SetCompare_0017f5c0(int value) {
    *(int*)((char*)this + 0x10) = value;
    return 1;
}

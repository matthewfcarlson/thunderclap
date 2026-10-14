class X_146fc0 {
  public:
    char pad[0x44];
    char Set(int v);
};
char X_146fc0::Set(int v) {
    *(int*)((char*)this + 0x44) = v;
    return 1;
}

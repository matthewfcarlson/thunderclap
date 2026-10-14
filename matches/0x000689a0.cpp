class X_689a0 {
  public:
    char pad[0x10];
    char Set(int v);
};

char X_689a0::Set(int v) {
    *(int*)((char*)this + 0x10) = v;
    return 1;
}

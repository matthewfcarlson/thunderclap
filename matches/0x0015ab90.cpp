class O_15ab90 {
  public:
    char pad[0x20];
    char Set(int v);
};

char O_15ab90::Set(int v) {
    *(int*)((char*)this + 0x20) = v;
    return 1;
}

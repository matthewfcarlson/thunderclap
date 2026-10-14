class O {
  public:
    char pad[0x20];
    char Set(int v);
};

char O::Set(int v) {
    *(int*)((char*)this + 0x20) = v;
    return 1;
}

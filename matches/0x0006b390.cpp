class C_6b390 {
  public:
    char Set(int v);
    char pad[0x28];
};

char C_6b390::Set(int v) {
    *(int*)((char*)this + 0x28) = v;
    return 1;
}

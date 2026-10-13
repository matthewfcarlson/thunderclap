class C {
  public:
    char Set(int v);
    char pad[0x28];
};

char C::Set(int v) {
    *(int*)((char*)this + 0x28) = v;
    return 1;
}

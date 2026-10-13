class C {
    char pad[0xc];

  public:
    char Set(int v);
};
char C::Set(int v) {
    *(int*)((char*)this + 0xc) = v;
    return 1;
}

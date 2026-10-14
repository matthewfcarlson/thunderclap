class C_68260 {
    char pad[0xc];

  public:
    char Set(int v);
};
char C_68260::Set(int v) {
    *(int*)((char*)this + 0xc) = v;
    return 1;
}

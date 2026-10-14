class C_16fad0 {
  public:
    char Fn(int x);
    char pad[0xc];
};

char C_16fad0::Fn(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}

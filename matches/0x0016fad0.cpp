class C {
  public:
    char Fn(int x);
    char pad[0xc];
};

char C::Fn(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}

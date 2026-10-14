class X {
  public:
    char Fn(int a);
};
char X::Fn(int a) {
    *(int*)((char*)this + 0x80) = a;
    return 1;
}
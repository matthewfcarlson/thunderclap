class X_192470 {
  public:
    char Fn(int a);
};
char X_192470::Fn(int a) {
    *(int*)((char*)this + 0x80) = a;
    return 1;
}
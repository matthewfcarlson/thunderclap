class A_10c4d0 {
  public:
    char Fn(int x);
};
char A_10c4d0::Fn(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}
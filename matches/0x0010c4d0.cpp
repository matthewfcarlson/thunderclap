class A_10c4d0 {
  public:
    char SetTimeBegin_0010c4d0(int x);
};
char A_10c4d0::SetTimeBegin_0010c4d0(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}
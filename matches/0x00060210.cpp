class A_60210 {
  public:
    char f(int x);
};
char A_60210::f(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}

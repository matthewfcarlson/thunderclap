class C_44630 {
  public:
    char pad[0xa0];
    int f(int i);
};
int C_44630::f(int i) {
    if (!i)
        return -1;
    return *(int*)((char*)this + 0xa0 + i * 4);
}
class C {
  public:
    char pad[0xa0];
    int f(int i);
};
int C::f(int i) {
    if (!i)
        return -1;
    return *(int*)((char*)this + 0xa0 + i * 4);
}
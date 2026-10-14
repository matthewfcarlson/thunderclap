class C {
  public:
    virtual void A();
    int F(int a, int b);
    int* mP;
};
int C::F(int a, int b) {
    int* p = mP;
    if (!p)
        return -1;
    *(int*)((char*)p + 0x1d34) = 0;
    return 0;
}

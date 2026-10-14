class C_bbe90 {
  public:
    virtual void A();
    int F(int a, int b);
    int* mP;
};
int C_bbe90::F(int a, int b) {
    int* p = mP;
    if (!p)
        return -1;
    *(int*)((char*)p + 0x1d34) = 0;
    return 0;
}

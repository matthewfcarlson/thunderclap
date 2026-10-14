class C_1d63b0 {
    char pad[0x108];
    int value;
    char gap[4];
    char flag;

  public:
    void Set(int x);
};
void C_1d63b0::Set(int x) {
    value = x;
    if (x > 0)
        flag = 1;
}
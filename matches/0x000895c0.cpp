class C_895c0 {
    char pad[0xab8];
    int value;

  public:
    void Set(int);
};
void C_895c0::Set(int x) {
    value = x;
    if (x < 0 || 2 < x)
        value = 1;
}
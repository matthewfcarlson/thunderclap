class C_36140 {
    char pad[0x114];
    int value;

  public:
    void f(char b);
};
void C_36140::f(char b) {
    if (b)
        ++value;
    else
        --value;
}
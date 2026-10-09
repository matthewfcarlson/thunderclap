class C {
    char pad[0x114];
    int value;

  public:
    void f(char b);
};
void C::f(char b) {
    if (b)
        ++value;
    else
        --value;
}
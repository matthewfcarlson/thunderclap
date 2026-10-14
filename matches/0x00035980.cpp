class C_35980 {
    char pad[0x138];
    int value;

  public:
    void f(bool x);
};
void C_35980::f(bool x) {
    if (x)
        ++value;
    else
        --value;
}
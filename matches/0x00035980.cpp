class C {
    char pad[0x138];
    int value;

  public:
    void f(bool x);
};
void C::f(bool x) {
    if (x)
        ++value;
    else
        --value;
}
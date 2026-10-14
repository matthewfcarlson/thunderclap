class X_361f0 {
    char pad[0x1b20];

  public:
    int value;
    void f(char b);
};
void X_361f0::f(char b) {
    if (b)
        ++value;
    else
        --value;
}
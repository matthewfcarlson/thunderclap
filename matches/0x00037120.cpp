class X_37120 {
  public:
    char pad[0x22ac];
    int value;
    void f(bool b);
};
void X_37120::f(bool b) {
    if (b)
        ++value;
    else
        --value;
}
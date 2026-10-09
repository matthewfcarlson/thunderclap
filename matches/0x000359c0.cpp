class C {
    char pad[0x13c];
    int value;

  public:
    void Set(int x);
};
void C::Set(int x) {
    if (value == 0 || x == value || x > value)
        value = x;
}
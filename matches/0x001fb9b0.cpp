class C {
    char pad[0x1c];
    int value;

  public:
    void Set(int x);
};
void C::Set(int x) {
    value = x;
}
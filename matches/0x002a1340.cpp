class C {
  public:
    char pad[0x30];
    int value;
    void Set(int x);
};
void C::Set(int x) {
    value = x;
}
class C {
  public:
    char pad[0x10c];
    int value;
    void Set(int);
};
void C::Set(int x) {
    value = x;
}
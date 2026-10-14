class C {
  public:
    char pad[0x90];
    int field;
    void Set(int value);
};
void C::Set(int value) {
    field = value;
}
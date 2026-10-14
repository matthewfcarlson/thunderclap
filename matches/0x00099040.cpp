class C {
  public:
    char pad[0x94];
    int field;
    void SetField(int value);
};
void C::SetField(int value) {
    field = value;
}

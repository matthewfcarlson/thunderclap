class Target {
  public:
    char pad[0x37e];
    char value;
    void SetValue(char v);
};
void Target::SetValue(char v) {
    value = v;
}

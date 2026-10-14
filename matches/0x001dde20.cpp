class Target {
  public:
    char pad[0x1eee4];
    int m1eee4;
    void Set(int value);
};
void Target::Set(int value) {
    m1eee4 = value;
}

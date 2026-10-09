class Target {
    char pad[0x1e0];

  public:
    void Set(unsigned char value);
};
void Target::Set(unsigned char value) {
    pad[0x1e0] = value;
}
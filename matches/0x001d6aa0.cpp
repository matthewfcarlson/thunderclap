class Target_1d6aa0 {
    char pad[0x1e0];

  public:
    void Set(unsigned char value);
};
void Target_1d6aa0::Set(unsigned char value) {
    pad[0x1e0] = value;
}
class Target {
  public:
    char pad[0x22fc];
    unsigned char value;
    void set(unsigned char);
};
void Target::set(unsigned char x) {
    value = x;
}
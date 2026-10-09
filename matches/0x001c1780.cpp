class Target {
    char pad[0xD9];

  public:
    unsigned char value;
    void Set(unsigned char v);
};
void Target::Set(unsigned char v) {
    value = v;
}
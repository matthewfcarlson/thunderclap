class Target_1d6290 {
    char pad[0xf9];

  public:
    unsigned char value;
    void Set(unsigned char x);
};
void Target_1d6290::Set(unsigned char x) {
    value = x;
}
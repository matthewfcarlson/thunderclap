class Target_89a30 {
    char pad[0xabd];

  public:
    void Set(unsigned char value);
};
void Target_89a30::Set(unsigned char value) {
    *((unsigned char*)this + 0xabd) = value;
}
class C {
    char pad[0x350];

  public:
    unsigned int value;
    unsigned int target();
};
unsigned int C::target() {
    return value;
}
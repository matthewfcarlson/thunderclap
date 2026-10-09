class C {
  public:
    char pad[0x90];
    unsigned int value;
    unsigned int get();
};
unsigned int C::get() {
    return value;
}
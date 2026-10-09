class C {
  public:
    char pad[0xac];
    unsigned int value;
    unsigned int get();
};
unsigned int C::get() {
    return value;
}
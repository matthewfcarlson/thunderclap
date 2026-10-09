class C {
    char pad[0x24c];

  public:
    int value;
    int get();
};
int C::get() {
    return value;
}
class X {
  public:
    char pad0[0x10];
    unsigned count;
    char pad14[8];
    unsigned* items;
    unsigned get(unsigned i);
};
unsigned X::get(unsigned i) {
    if (i < count)
        return items[i];
    return 0;
}
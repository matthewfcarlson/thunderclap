class Thing_245cd0 {
  public:
    char pad[0x90];
    int line;
    unsigned int index;
    unsigned int limit;
    char Get(unsigned int);
    void Step();
};
void Thing_245cd0::Step() {
    unsigned int i = index;
    if (i < limit) {
        if (Get(i) == 10)
            ++line;
        ++index;
    }
}
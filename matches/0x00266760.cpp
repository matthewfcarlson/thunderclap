class Thing_266760 {
    char pad[0x14];

  public:
    int state;
    void Wait();
};
void thunk();
void step();
void Thing_266760::Wait() {
    while (state != 3) {
        thunk();
        step();
    }
}
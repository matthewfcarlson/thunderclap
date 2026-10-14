class Other_1eb2a0 {
  public:
    void target(int, int);
};
class Thing_1eb2a0 {
  public:
    char pad[8];
    unsigned char enabled;
    void run(int a, int b);
};
void Thing_1eb2a0::run(int a, int b) {
    if (enabled)
        ((Other_1eb2a0*)*(void**)this)->target(a, b);
}
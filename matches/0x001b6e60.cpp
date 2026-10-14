class Thing_1b6e60 {
  public:
    int a[6];
    void fallback(int);
    void target(int);
};
void Thing_1b6e60::target(int param) {
    int i = 0;
    do {
        if (a[i * 2] == param) {
            a[i * 2 + 1] = 0x3e800000;
            return;
        }
        ++i;
    } while (i < 3);
    fallback(param);
}
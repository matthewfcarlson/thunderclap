class X {
    char pad[0x90];

  public:
    int lines;
    unsigned int pos, end;
    char Get(unsigned int);
    void Skip(unsigned int);
};
void X::Skip(unsigned int n) {
    while (n) {
        if (pos < end) {
            if (Get(pos) == '\n')
                ++lines;
            ++pos;
        }
        --n;
    }
}
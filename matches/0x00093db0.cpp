struct ThisWrap_00093db0 {
    void Other(int, int);
    void Target(int n, int unused);
};
void ThisWrap_00093db0::Target(int n, int unused) {
    if (n >= 0 && n < 0x2fe)
        this->Other(n, unused);
}
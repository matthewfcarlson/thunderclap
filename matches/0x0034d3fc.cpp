// cl-flags: /Oy- /O1
class DName {
  public:
    DName(unsigned long u);
    void doPchar(const char* s, int n);
    unsigned int mFlags;
    unsigned short m4;
};
DName::DName(unsigned long u) {
    m4 &= 0xfe00;
    char buf[12];
    char neg;
    char* p = buf + 11;
    mFlags = 0;
    *p = 0;
    neg = 0;
    if ((int)u < 0) {
        neg = 1;
        u = -(int)u;
    }
    do {
        *--p = (char)((int)u % 10) + '0';
        u = u / 10;
    } while (u != 0);
    if (neg != 0)
        *--p = '-';
    doPchar(p, buf + 11 - p);
}

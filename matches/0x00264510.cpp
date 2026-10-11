struct S {
    char p0[0xc];
    char m0c;
    char pd;
    char m0e;
    char pf[5];
    unsigned m14;
    char p18[0x14];
    unsigned m2c, m30;
    void A(unsigned);
    void B();
    void f(unsigned n);
};
void S::f(unsigned n) {
    if (m0c && n) {
        if (!m0e) {
            A(n);
            return;
        }
        unsigned t = m2c + n;
        if (t <= m30) {
            m2c = t;
            m14 += n;
            return;
        }
        unsigned left = n;
        if (left > 0) {
            for (;;) {
                unsigned c = m2c;
                unsigned k = left;
                if (c + left > m30)
                    k = m30 - c;

                m2c += k;
                m14 += k;
                left -= k;
                if (left == 0)
                    break;
                B();
            }
        }
    }
}

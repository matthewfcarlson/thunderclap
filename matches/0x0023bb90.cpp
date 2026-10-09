struct Stream {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Write(void* p, unsigned n);
};
struct W {
    char p0[8];
    Stream* s;
    char p1;
    char sw;
    char p1b[0x12];
    unsigned remain;
    char p2[4];
    char buf[8];
    char pend;
    void Flush();
};
void W::Flush() {
    if (pend) {
        unsigned junk;
        while (remain > 0) {
            unsigned n = remain;
            if (n > 4)
                n = 4;
            s->Write(&junk, n);
            remain -= n;
        }
        s->Write(buf, 8);
        if (sw) {
            char* a = &buf[0];
            char* b = a + 7;
            while (a < b) {
                char t = *a;
                *a = *b;
                a++;
                *b = t;
                b--;
            }
        }
        pend = 0;
    }
}

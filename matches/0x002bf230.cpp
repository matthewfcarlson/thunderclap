class ImageFont {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual unsigned int vfunc_10(const short* s);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual unsigned int Width(const short* s);
};
unsigned int ImageFont::vfunc_10(const short* s) {
    if (!s)
        return 0;
    unsigned int best = 0;
    int i = 0;
    if (*s != 0) {
        const short* p = s;
        do {
            unsigned int w = Width(p);
            if (w > best)
                best = w;
            short c = *p;
            while (c != 0 && c != 10) {
                i++;
                c = s[i];
            }
            p = s + i;
        } while (*p != 0);
    }
    return best;
}

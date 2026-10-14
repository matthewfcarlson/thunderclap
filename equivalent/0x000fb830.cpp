// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 39/46, incomplete)
// FUN_000fb830 @ 0x000fb830
struct Measurer_fb830 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual float MeasureWidth(const unsigned short* text);
};
struct Settings_fb830 {
    char pad[0x10c];
    int mode;
};
Settings_fb830* __cdecl FUN_000fc1b0();

int FUN_000fb830(unsigned short* out, int bufSize, const unsigned short* in, float maxWidth, Measurer_fb830* m) {
    if (bufSize == 2) return 1;
    const unsigned short* breakChars = (FUN_000fc1b0()->mode == 3) ? (const unsigned short*)L"):-\x200b\x3000\x3001\x3002\x3006\x3009\x300b\x300d\x300f\x3011\x3015\x3017\x3019\x301b\x3092\x30fb\xff01\xff09\xff1a\xff1f\xff61\xff64" : (const unsigned short*)L"-";
    unsigned short* cur = out;
    unsigned short* breakOut = 0;
    const unsigned short* breakIn = 0;
    unsigned short* lineStart = out;
    int lines = 1;
    *cur = 0;
    if (*in == 0) { *cur = 0; return lines; }
    unsigned int limit = bufSize - 4;
    for (;;) {
        if ((unsigned int)(cur - out) >= limit) break;
        unsigned short c = *in;
        if (c == 0) break;
        *cur = c;
        unsigned short* next = cur + 1;
        *next = 0;
        if (in[1] == 0) { cur = next; break; }
        if (*in == '\n') {
            breakOut = 0;
            breakIn = 0;
            lines++;
            lineStart = next;
        } else {
            if (m->MeasureWidth(lineStart) < maxWidth || breakOut == 0) {
                unsigned short d = *in;
                if (d == ' ' || d == 0x200b) {
                    breakOut = cur;
                    breakIn = in;
                } else {
                    for (const unsigned short* p = breakChars; *p != 0; p++) {
                        if (d == *p) {
                            breakOut = next;
                            breakIn = in;
                            break;
                        }
                    }
                }
            }
            if (!(m->MeasureWidth(lineStart) < maxWidth) && breakOut != 0) {
                while (breakOut > out && breakOut[-1] == ' ') breakOut--;
                lineStart = breakOut + 1;
                breakOut[1] = 0;
                breakOut[0] = '\n';
                cur = breakOut;
                in = breakIn;
                const unsigned short* p = breakIn + 1;
                while (*p == ' ') {
                    in = p;
                    p++;
                }
                lines++;
                breakOut = 0;
                breakIn = 0;
            }
        }
        in++;
        cur++;
        if (*in == 0) { *cur = 0; return lines; }
    }
    *cur = 0;
    return lines;
}

// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 48/50, incomplete)
// FUN_000fba10 @ 0x000fba10
typedef unsigned short wc;

class Measurer_fba10 {
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
    virtual float measure(const wc *text);
};

struct Manager_fba10 {
    char pad[0x10c];
    int language;
};
Manager_fba10 *__cdecl FUN_000fc1b0();
extern const wc DAT_0040cf10[];
extern const wc DAT_0040cf14[];

int __cdecl FUN_000fba10(wc **lines, int maxLines, int maxChars, const wc *src, float maxWidth,
                         Measurer_fba10 *m)
{
    if (maxChars == 2)
        return 1;

    const wc *breakSet = (FUN_000fc1b0()->language == 3) ? DAT_0040cf14 : DAT_0040cf10;
    wc *dst = lines[0];
    const wc *brkSrc = 0;
    wc *brkDst = 0;
    int line = 1;
    *dst = 0;
    wc *lineStart = dst;

    while (*src != 0) {
        bool newLine = false;
        if (line > maxLines)
            break;
        if ((unsigned)(dst - lines[line - 1]) >= (unsigned)(maxChars - 4))
            break;
        wc c = *src;
        if (c == 0)
            break;
        *dst = c;
        dst[1] = 0;
        if (src[1] == 0) {
            dst++;
            break;
        }
        if (*src == 0xa) {
            *dst = 0;
            dst = lines[line];
            brkDst = 0;
            brkSrc = 0;
            line++;
            lineStart = dst;
            newLine = true;
        } else {
            if (m->measure(lineStart) < maxWidth || brkDst == 0) {
                wc ch = *src;
                if (ch == 0x20 || ch == 0x200b) {
                    brkDst = dst;
                    brkSrc = src;
                } else {
                    for (const wc *b = breakSet; *b != 0; b++) {
                        if (ch == *b) {
                            brkDst = dst + 1;
                            brkSrc = src;
                            break;
                        }
                    }
                }
            }
            if (m->measure(lineStart) >= maxWidth && brkDst != 0) {
                wc *start = lines[line - 1];
                wc *e = brkDst;
                while (e > start && e[-1] == 0x20)
                    e--;
                *e = 0;
                *dst = 0;
                dst = lines[line];
                src = brkSrc;
                const wc *q = brkSrc + 1;
                wc cx = *q;
                while (cx != 0 && cx == 0x20) {
                    src = q;
                    cx = src[1];
                    q = src + 1;
                }
                lineStart = dst;
                brkDst = 0;
                brkSrc = 0;
                line++;
                newLine = true;
            }
        }
        src++;
        if (!newLine)
            dst++;
    }
    *dst = 0;
    return line;
}

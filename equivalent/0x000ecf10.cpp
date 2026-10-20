// STATUS: equivalent (tools/equiv.py level 3: 4234 inputs, branch coverage 48/52, incomplete)
// FUN_000ecf10 @ 0x000ecf10
// cl-flags: /GS
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
#include "compat/ptr.h"
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
extern "C" void *__cdecl memset(void *, int, unsigned int);

union Word_ecf10 {
    float f;
    int i;
    unsigned int u;
};

struct Cell_ecf10 {
    Word_ecf10 a, b, c, d;
};

// The font object a Builder is set up with: slot 7 = line height, slot 10 = width of a string.
class Font {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    virtual void v8();
    virtual void v9();
    virtual float v10(const unsigned short *text);
};

struct Source_ecf10;

struct FontRef {
    char pad00[0x24];
    Font *font;                      // 0x24
};

struct Builder {
    FontRef *face;                   // 0x00
    unsigned int hdr1;
    Cell_ecf10 cells[8];
    int cursor;                      // 0x88
    float scale;
    void FUN_000f7fe0(Source_ecf10 *src);
    void FUN_000f78e0();
};

class Source_ecf10 {
public:
    virtual void v0();
};

class Level2_ecf10 {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual Source_ecf10 *v44();
};

struct Level1_ecf10 {
    char pad0[4];
    Level2_ecf10 *level2;
};

class TextBox_ecf10;

class Owner_ecf10 {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual float v16(TextBox_ecf10 *obj);
    virtual float v17(TextBox_ecf10 *obj);
    char pad04[4];
    Level1_ecf10 *p8;
};

struct StringTable_ecf10 {
    unsigned short *FUN_000f83f0(FontRef *face, int zero);
};

void __cdecl thunk_FUN_00267090(void *p);
void *__cdecl FUN_0008d6d0(unsigned int size);

class TextBox_ecf10 {
public:
    char pad00[0x14];
    Owner_ecf10 *owner;                    // 0x14
    StringTable_ecf10 strings;             // 0x18
    char pad19[0x15c - 0x19];
    unsigned short *buf;                    // 0x15c
    int cap;                         // 0x160
    unsigned short *lines[0x200];           // 0x164
    int count;                       // 0x964
    char pad968[4];
    int first;                       // 0x96c
    char pad970[4];
    int lastLine;                    // 0x974

    void FUN_000ecf10(float maxWidth);
};

void TextBox_ecf10::FUN_000ecf10(float maxWidth)
{
    struct Frame {
        unsigned short *out;                // 0x04
        union {                             // 0x08: first the scale factor, later the read cursor
            const unsigned short *p;
            float t14;
        } src_;
        unsigned short *lineEnd;            // 0x0c
        const unsigned short *wordStart;    // 0x10
        union Slot {                 // 0x14: cell pointer spilled across the line-height call, then the scale
            float * volatile p;
            volatile float f;
        } u;
        Font *font;                  // 0x18
        Builder x;                   // 0x1c
        unsigned short line[0x80];          // 0xac
        char gap[4];
    } f;

    f.x.FUN_000f7fe0(owner->p8->level2->v44());
    f.src_.t14 = owner->v17(this);
    f.x.cells[f.x.cursor].a.f = owner->v16(this) * f.src_.t14;
    if (buf != 0) {
        thunk_FUN_00267090(buf);
        buf = 0;
    }
    buf = 0;
    cap = 0;
    memset(lines, 0, sizeof(lines));
    count = 0;
    lastLine = 0;
    first = 0;
    const unsigned short *text = strings.FUN_000f83f0(f.x.face, 0);
    if (text == 0) {
        f.x.FUN_000f78e0();
        return;
    }

    int len = 0;
    while (text[len] != 0)
        len++;
    int need = 1 - (int)((float)len * -1.25f);
    cap = need;
    if (need > 0) {
        buf = (unsigned short *)FUN_0008d6d0(need * 2);
        if (buf == 0) {
            f.x.FUN_000f78e0();
            return;
        }
    }

    f.out = buf;
    lines[count] = f.out;
    f.wordStart = text;
    f.src_.p = text;
    f.lineEnd = f.line;
    bool afterSpace = true;
    if (*f.src_.p != 0) {
        do {
            unsigned short ch = *f.src_.p;
            if (ch != 0x20 && afterSpace)
                f.wordStart = f.lineEnd;
            *f.lineEnd = ch;
            f.lineEnd++;
            *f.lineEnd = 0;
            bool flush = *f.src_.p == 0xa || (((char *)f.lineEnd - (char *)f.line) & ~1) == 0x100;
            if (flush) {
                *f.lineEnd = 0;
                int n = 0;
                while (f.line[n] != 0)
                    n++;
                if (*f.src_.p == 0xa)
                    n--;
                memcpy(f.out, f.line, n * 2);
                unsigned short *end = f.out + n;
                *end = 0;
                count++;
                if (!(count < 0x200))
                    count = 0x200;
                f.out = end + 1;
                lines[count] = f.out;
                f.lineEnd = f.line;
            }
            f.font = f.x.face->font;
            f.u.p = &f.x.cells[f.x.cursor].a.f;
            f.u.f = *f.u.p / f.font->v7();
            if (f.font->v10(f.line) * f.u.f * 14.0f >= maxWidth) {
                hulk_intptr wi = f.wordStart - f.line;
                *f.lineEnd = 0;
                unsigned short *o;
                const unsigned short *brk;
                if (wi == 0) {
                    hulk_intptr n = (f.lineEnd - f.line) - 1;
                    memcpy(f.out, f.line, n * 2);
                    o = f.out + n;
                    *o = 0x2d;
                    o++;
                    brk = f.lineEnd;
                    f.wordStart = brk;
                } else {
                    memcpy(f.out, f.line, wi * 2);
                    o = f.out + wi;
                    brk = f.wordStart;
                }
                *o = 0;
                count++;
                if (!(count < 0x200))
                    count = 0x200;
                o++;
                f.out = o;
                lines[count] = o;
                hulk_intptr rest = f.lineEnd - brk;
                if (rest >= 0) {
                    memcpy(f.line, brk, rest * 2);
                    f.lineEnd = f.line + rest;
                } else {
                    f.lineEnd = f.line;
                    f.wordStart = f.line;
                }
            }
            afterSpace = *f.src_.p == 0x20;
            f.src_.p++;
        } while (*f.src_.p != 0);
    }

    *f.lineEnd = 0;
    int n = 0;
    while (f.line[n] != 0)
        n++;
    if (n > 0) {
        memcpy(f.out, f.line, n * 2);
        f.out = f.out + n;
        *f.out = 0;
        count++;
        if (!(count < 0x200))
            count = 0x200;
        lines[count] = f.out;
    }
    *f.out = 0;
    lastLine = count > 0 ? count - 1 : 0;

    f.x.FUN_000f78e0();
}

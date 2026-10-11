// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 20/20)
// FUN_00300a00 @ 0x00300a00
void *FUN_0008d6d0(unsigned int size);

extern unsigned int DAT_004d2ef0;
extern unsigned int DAT_004d2ef4;
extern unsigned int DAT_004d2ef8;
extern unsigned int DAT_004d2efc;
extern unsigned int DAT_004d2f00;

struct Buffer {
    char *begin;
    char *end;
    char *cap;
    unsigned int pad;
};

class Pools {
public:
    Buffer a;
    Buffer c;
    Buffer d;
    Buffer b;
    Buffer e;
    unsigned char flag;
    char pad51[3];
    unsigned int f54, f58, f5c, f60, f64, f68;

    Pools *FUN_00300a00();
};

Pools *Pools::FUN_00300a00()
{
    a.begin = 0;
    a.end = 0;
    a.cap = 0;
    c.begin = 0;
    c.end = 0;
    c.cap = 0;
    d.begin = 0;
    d.end = 0;
    d.cap = 0;
    b.begin = 0;
    b.end = 0;
    b.cap = 0;
    e.begin = 0;
    e.end = 0;
    e.cap = 0;
    flag = 0;

    if (DAT_004d2ef0 != 0) {
        unsigned int bytes = DAT_004d2ef0 * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        a.begin = p;
        if (p != 0) {
            a.end = p;
            a.cap = p + bytes;
        } else {
            a.end = 0;
            a.cap = 0;
        }
    } else {
        a.begin = 0;
        a.end = 0;
        a.cap = 0;
    }

    if (DAT_004d2efc != 0) {
        unsigned int bytes = DAT_004d2efc * 20;
        char *p = (char *)FUN_0008d6d0(bytes);
        b.begin = p;
        if (p != 0) {
            b.end = p;
            b.cap = p + bytes;
        } else {
            b.end = 0;
            b.cap = 0;
        }
    } else {
        b.begin = 0;
        b.end = 0;
        b.cap = 0;
    }

    if (DAT_004d2ef4 != 0) {
        unsigned int bytes = DAT_004d2ef4 * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        c.begin = p;
        if (p != 0) {
            c.end = p;
            c.cap = p + bytes;
        } else {
            c.end = 0;
            c.cap = 0;
        }
    } else {
        c.begin = 0;
        c.end = 0;
        c.cap = 0;
    }

    if (DAT_004d2ef8 != 0) {
        unsigned int bytes = DAT_004d2ef8 * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        d.begin = p;
        if (p != 0) {
            d.end = p;
            d.cap = p + bytes;
        } else {
            d.end = 0;
            d.cap = 0;
        }
    } else {
        d.begin = 0;
        d.end = 0;
        d.cap = 0;
    }

    if (DAT_004d2f00 != 0) {
        unsigned int bytes = DAT_004d2f00 * 0x44;
        char *p = (char *)FUN_0008d6d0(bytes);
        e.begin = p;
        if (p != 0) {
            e.end = p;
            e.cap = p + bytes;
        } else {
            e.end = 0;
            e.cap = 0;
        }
    } else {
        e.begin = 0;
        e.end = 0;
        e.cap = 0;
    }

    f54 = 0;
    f58 = 0;
    f5c = 0;
    f60 = 0;
    f64 = 0;
    f68 = 0;
    return this;
}

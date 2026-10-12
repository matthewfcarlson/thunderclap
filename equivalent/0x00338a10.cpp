// STATUS: equivalent (tools/equiv.py level 3: 3041 inputs, branch coverage 76/82, incomplete)
// FUN_00338a10 @ 0x00338a10
class Source {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Read(char *buf, int size);
    virtual bool AtEnd();
};

class Tokenizer {
public:
    char pad00[4];
    Source *source;
    int bufSize;
    int pos;
    int len;
    char pad14[4];
    char *buf;
    char tok[0x400];
    char cur[0x400];
    int status;
    char done;
    char flag821;
    char pad822[2];
    int lineno;
    char saved;
    char pad829[3];
    char *savedEnd;
    char savedQuote;
    char savedFlagB;
    char pad832[0x85a - 0x832];
    char delim[0x18];
    char flag872;
    char *FUN_00338a10();
    char *FUN_00338800(char *s);
    bool FUN_003387d0(int ch);
    bool FUN_003387a0(int ch);
    bool FUN_00338860(char *s);
};

char *Tokenizer::FUN_00338a10()
{
    struct Frame {
        char pad[2];
        char flagB;
        char inQuote;
        char *tokstart;
        char *curp;
        union {
            char c;
            int w;
        } ch;
    } f;
    char *out;
    char c;

    if (status)
        return 0;
    if (done)
        return tok;

    out = tok;
    f.tokstart = out;
    f.inQuote = 0;
    f.flagB = 0;
    if (saved) {
        f.inQuote = savedQuote;
        f.flagB = savedFlagB;
        out = savedEnd;
        saved = 0;
    } else {
        *out = 0;
    }

    f.curp = cur;
    c = cur[0];
    if (c != 0) {
        if (c == '"') {
            f.inQuote = 1;
        } else {
            if (FUN_00338800(cur)) {
                char *d = f.tokstart;
                char *s = cur;
                char t;
                do {
                    t = *s;
                    *d = t;
                    s++;
                    d++;
                } while (t);
                cur[0] = t;
                done = 1;
                return f.tokstart;
            }
            if (c == '\n')
                lineno++;
        }
    }
    cur[0] = 0;

    for (;;) {
        if (pos < len) {
            c = buf[pos];
            pos++;
        } else {
            if (!source->AtEnd()) {
                if (source->AtEnd()) {
                    savedEnd = out;
                    savedQuote = f.inQuote;
                    saved = 1;
                    savedFlagB = f.flagB;
                    return 0;
                }
                status = (f.inQuote != 0) + 1;
                return done ? f.tokstart : 0;
            }
            len = source->Read(buf, bufSize);
            pos = 0;
            if (len <= 0) {
                if (source->AtEnd()) {
                    savedEnd = out;
                    savedQuote = f.inQuote;
                    saved = 1;
                    savedFlagB = f.flagB;
                    return 0;
                }
                status = (f.inQuote != 0) + 1;
                return done ? f.tokstart : 0;
            }
            c = buf[0];
            pos = 1;
        }
        f.ch.c = c;
        int chw = f.ch.w;
        if (FUN_003387d0(chw))
            continue;
        if (!f.inQuote && !f.flagB) {
            if (FUN_003387a0(chw)) {
                if (out - tok <= 0)
                    continue;
                break;
            }
        }
        if (c == '\n') {
            if (!f.inQuote) {
                if (out - tok > 0) {
                    if (f.flagB)
                        flag821 = 1;
                    cur[0] = '\n';
                    cur[1] = 0;
                    break;
                }
                lineno = lineno + 1;
                f.flagB = 0;
                continue;
            }
            lineno++;
        }
        if (!f.flagB && c == '"') {
            if (f.inQuote)
                break;
            if (out - tok > 0) {
                cur[0] = '"';
                cur[1] = 0;
                break;
            }
            f.inQuote = 1;
            continue;
        }
        if (flag872 != 0 || f.flagB == 0) {
            if (out - tok >= 0x3ff) {
                status = 3;
                return 0;
            }
            *out = c;
            out++;
            *out = 0;
        }
        if (f.inQuote)
            continue;
        {
            char *ts = f.tokstart;
            if (!f.flagB) {
                char *m = FUN_00338800(ts);
                if (m) {
                    int l1 = 0;
                    while (ts[l1])
                        l1++;
                    int l2 = 0;
                    while (m[l2])
                        l2++;
                    if (l1 > l2) {
                        char *d = f.curp;
                        char *s = m;
                        char t;
                        do {
                            t = *s;
                            *d = t;
                            s++;
                            d++;
                        } while (t);
                        tok[l1 - l2] = t;
                    }
                    break;
                }
            }
            if (!FUN_00338860(ts))
                continue;
            out = f.tokstart;
            int l1 = 0;
            while (out[l1])
                l1++;
            int l2 = 0;
            while (delim[l2])
                l2++;
            if (l1 > l2) {
                char *d = f.curp;
                char *s = delim;
                char t;
                do {
                    t = *s;
                    *d = t;
                    s++;
                    d++;
                } while (t);
                tok[l1 - l2] = t;
                break;
            }
            f.flagB = 1;
            *out = 0;
        }
    }
    done = 1;
    return f.tokstart;
}

// STATUS: equivalent (tools/equiv.py level 3: 247 inputs, branch coverage 22/22)
// FUN_00355e2d @ 0x00355e2d
typedef unsigned short wchar_t;
extern "C" unsigned int wcslen(const wchar_t *s);
extern "C" wchar_t *wcsstr(const wchar_t *s, const wchar_t *sub);
extern "C" wchar_t *wcsncpy(wchar_t *dst, const wchar_t *src, unsigned int n);
extern "C" void *memmove(void *dst, const void *src, unsigned int n);

int __stdcall FUN_0020ff8d(void *file, void *buf, unsigned int bytes, unsigned int *bytesRead, int overlapped);
int __stdcall FUN_002101d4(void *file, int distance, int highPart, int method);

struct Frame_355e2d {
    wchar_t buf[0x8c];
    short unused;
    int keyLen;
    int result;
    unsigned int bytesRead;
    int done;
    int cap;
    int pad;   // the original has an ebp frame, which puts buf 4 bytes lower than this frameless build does
};

// Reads "key=value" from a UTF-16 text file read in chunks; copies the value into out.
int __stdcall FUN_00355e2d(void *file, const wchar_t *key, wchar_t *out, int outMax)
{
    Frame_355e2d f;
    wchar_t *p;
    int skipLine = 0;
    f.result = 0;
    p = f.buf;
    f.cap = 0x8c;
    f.done = 0;
    f.keyLen = (int)wcslen(key);
    f.unused = 0;
    for (;;) {
        if (f.done == 0) {
            if (!FUN_0020ff8d(file, p, f.cap * 2, &f.bytesRead, 0))
                break;
            if (f.bytesRead == 0)
                break;
        }
        f.done = 0;
        unsigned int total = f.bytesRead + (unsigned int)((p - f.buf) * 2);
        if (skipLine) {
            p = f.buf;
            f.cap = 0x8c;
            wchar_t *eol = wcsstr(f.buf, L"\r\n");
            if (eol == 0)
                continue;
            unsigned int off = (unsigned int)((char *)eol - (char *)f.buf) + 4;
            if (off < total) {
                unsigned int rem = total - off;
                memmove(f.buf, (char *)f.buf + off, rem);
                p = (wchar_t *)((char *)f.buf + rem);
                f.cap = 0x8c - (int)(rem >> 1);
            }
            skipLine = 0;
            continue;
        }
        wchar_t *hit = wcsstr(f.buf, key);
        if (hit == 0 || *(wchar_t *)((char *)hit + f.keyLen * 2) != L'=') {
            skipLine = 1;
            f.done = 1;
            continue;
        }
        wchar_t *val = (wchar_t *)((char *)hit + f.keyLen * 2 + 2);
        p = val;
        wchar_t *eol = wcsstr(val, L"\r\n");
        if (eol == 0) {
            skipLine = 1;
            p = f.buf;
            f.cap = 0x8c;
            continue;
        }
        int len = (int)(eol - val);
        int n = outMax - 1;
        if (!(n < len))
            n = len;
        wcsncpy(out, val, n);
        out[n] = 0;
        unsigned int next = (unsigned int)((char *)eol - (char *)f.buf) + 4;
        if (next < total)
            FUN_002101d4(file, (int)(next - total), 0, 1);
        f.result = 1;
        break;
    }
    return f.result;
}

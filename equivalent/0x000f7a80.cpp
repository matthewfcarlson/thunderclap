// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 37/46, incomplete)
// FUN_000f7a80 @ 0x000f7a80
extern "C" void *memset(void *dst, int c, unsigned int n);
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int cookie);

void *__cdecl FUN_00263ea0(unsigned int size);
unsigned long long __cdecl FUN_0027b020(const char *s);

class File {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad04[8];
    char ok;
    File *FUN_00264430(const char *name, int a, int b);
    void FUN_002647e0(void *out, int a, int b, int c);
};

class StringTable {
public:
    unsigned short *pool;
    int poolCapacity;
    int used;
    unsigned short **strings;
    int maxStrings;
    int count;
    unsigned long long *hashes;
    int maxHashes;
    int hashCount;

    int FUN_000f7080(unsigned short *buf, int n, File *file);
    void FUN_000f76c0(unsigned short *line);
    int FUN_000f7790(unsigned short *line);
    bool FUN_000f7a80(const char *filename);
};

bool StringTable::FUN_000f7a80(const char *filename)
{
    unsigned int cookie = DAT_004d9968;
    unsigned short line[0x1000];
    char key[0x80];
    char hdr[4];

    const char *fn = filename;
    if (fn == 0 || *fn == 0)
        fn = "frontend\\lang\\str_en.txt";

    if (used != 0) {
        int bytes = maxStrings * 4;
        unsigned short **p = strings;
        used = 0;
        memset(p, 0, bytes);
    }

    File *file = 0;
    void *mem = FUN_00263ea0(0x48);
    if (mem != 0)
        file = ((File *)mem)->FUN_00264430(fn, 0, 1);

    if (file->ok == 0) {
        file->vfunc_1();
        __security_check_cookie(cookie);
        return false;
    }

    file->FUN_002647e0(hdr, 1, 2, 1);
    line[0] = *(unsigned short *)hdr;

    int more = FUN_000f7080(line, 0x1000, file);
    while (more != 0) {
        FUN_000f76c0(line);
        int n = FUN_000f7790(line) + 1;
        if (line[0] != '#' && line[0] != 0) {
            unsigned short *p = line;
            do {
                if (*p == ' ' || *p == '\t')
                    break;
                p++;
            } while (*p != 0);
            if (*p != 0) {
                *p = 0;
                unsigned short c = p[1];
                p++;
                if (c != 0) {
                    bool done = false;
                    while (c == ' ' || c == '\t') {
                        c = p[1];
                        p++;
                        if (c == 0) {
                            done = true;
                            break;
                        }
                    }
                    if (!done && *p != 0) {
                        n -= (int)(p - line);
                        char *d = key;
                        const unsigned short *s = line;
                        if (*s != 0) {
                            do {
                                *d++ = (char)*s;
                                s++;
                            } while (*s != 0);
                        }
                        *d = 0;
                        int start = used;
                        if ((start + n) * 2 > poolCapacity)
                            break;
                        memcpy((char *)pool + start * 2, p, n * 2);
                        int e = count;
                        used = used + n;
                        count = e + 1;
                        if (e >= maxStrings)
                            break;
                        strings[e] = (unsigned short *)((char *)pool + start * 2);
                        if (e >= maxHashes)
                            break;
                        hashes[e] = FUN_0027b020(key);
                        hashCount = e + 1;
                    }
                }
            }
        }
        more = FUN_000f7080(line, 0x1000, file);
    }
    file->vfunc_1();
    __security_check_cookie(cookie);
    return true;
}

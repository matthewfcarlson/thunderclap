// Our own glue for the i686 FFmpeg DLLs (tools/native_ffmpeg.py build --target win32): the C library names the
// mingw-w64 headers send to libmingwex (not linked here) and a few C99 functions the classic msvcrt.dll lacks,
// written over msvcrt.dll's exports. Compiled into each FFmpeg DLL; freestanding (no headers).
typedef __builtin_va_list va_list;

extern void* __iob_func(void);
extern int _vsnprintf(char*, unsigned, const char*, va_list);
extern int _vscprintf(const char*, va_list);
extern double strtod(const char*, char**);
extern double ldexp(double, int);
extern long long _strtoi64(const char*, char**, int);
extern unsigned long long _strtoui64(const char*, char**, int);
extern int _fstati64(int, void*);

// stdin / stdout / stderr: the headers' stderr is __acrt_iob_func(2); msvcrt's FILE is 32 bytes
void* __acrt_iob_func(unsigned i)
{
    return (char*)__iob_func() + i * 32u;
}

// C99 vsnprintf: the length the full output would have, and always terminated
int __ms_vsnprintf(char* buf, unsigned n, const char* fmt, va_list ap)
{
    va_list ap2;
    __builtin_va_copy(ap2, ap);
    int len = _vscprintf(fmt, ap2);
    __builtin_va_end(ap2);
    if (n) {
        int r = _vsnprintf(buf, n, fmt, ap);
        if (r < 0 || (unsigned)r >= n)
            buf[n - 1] = 0;
    }
    return len;
}

double __strtod(const char* s, char** end)
{
    return strtod(s, end);
}

long long strtoll(const char* s, char** end, int base)
{
    return _strtoi64(s, end, base);
}

unsigned long long strtoull(const char* s, char** end, int base)
{
    return _strtoui64(s, end, base);
}

int fstat32i64(int fd, void* st)
{
    return _fstati64(fd, st);
}

double scalbn(double x, int n)
{
    return ldexp(x, n);
}

// round to nearest even without the C library (SSE2 arithmetic: the add-and-subtract rounds in the FPU's mode)
float rintf(float x)
{
    const float big = 8388608.0f;
    float ax = x < 0 ? -x : x;
    if (!(ax < big))
        return x;
    volatile float t = ax + big;
    float r = t - big;
    return x < 0 ? -r : r;
}

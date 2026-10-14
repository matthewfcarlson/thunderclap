typedef unsigned int u32_33bca0;
typedef int (*Fn_33bca0)(void);
extern void f3390(void*, const char*, const char*, int);
extern void f213340(void*, u32_33bca0);
extern void f213790(void*, int, const char*);
extern void f2134a0(void*, Fn_33bca0, int);
extern int f33b880();
extern const char s_math[];
extern const char s_mptr[];
extern const char s_pi[];
extern const char s_pow[];
int target(void* p) {
    f3390(p, s_math, s_mptr, 0);
    f213340(p, 0x40490fdb);
    f213790(p, -2, s_pi);
    f2134a0(p, f33b880, 0);
    f213790(p, -10001, s_pow);
    return 1;
}
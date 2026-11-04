typedef unsigned int uint;
extern void f339dc0(void*, int);
extern int f213160(void*, int);
extern int f339e60(void*, int, const char*, int);
extern int f338e20(void*, const char*, ...);
extern void f212d80(void*, int);
extern "C" int FUN_0033e110(void* self, int arg) {
    f339dc0(self, 1);
    if (f213160(self, 1) == 0) {
        int x = f339e60(self, 2, "assertion failed!", 0);
        return f338e20(self, "%s", x);
    }
    f212d80(self, 1);
    return 1;
}
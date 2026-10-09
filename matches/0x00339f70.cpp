extern "C" int f213120(void*, void*);
extern "C" int f212f70(void*, void*);
extern "C" int f212f20(void*, int);
extern "C" int f212f00(void*, void*);
extern "C" int f213470(void*, const char*, int, int);
extern "C" void f339c30(void*, void*, int);
int g339f70(void* L, void* o) {
    int r = f213120(L, o);
    if (r == 0) {
        if (f212f70(L, o) == 0) {
            int a = f212f20(L, 3);
            int b = f212f20(L, f212f00(L, o));
            f339c30(L, o, f213470(L, "%s expected, got %s", a, b));
        }
    }
    return r;
}

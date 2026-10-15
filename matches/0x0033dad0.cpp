extern "C" void init();
extern "C" void a(void*, int);
extern "C" void b(void*, const char*, int);
extern "C" void c(void*, int);
extern "C" int d(void*, int);
extern "C" void e(void*, int);
int target(void* volatile p) {
    void* q = p;
    init();
    a(q, -1);
    b(q, "__fenv", 6);
    c(q, -2);
    if (d(q, -1) == 0)
        e(q, -2);
    return 1;
}
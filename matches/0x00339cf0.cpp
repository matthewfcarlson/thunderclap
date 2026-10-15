extern "C" int a(const char*, const char*);
extern "C" int b(const char*, int);
extern "C" int c(const char*, const char*, int, int);
extern "C" void d(const char*, const char*, int);
extern "C" const char fmt[];
void target(const char* x, const char* y, int z) {
    d(x, y, c(x, fmt, z, b(x, a(x, y))));
}
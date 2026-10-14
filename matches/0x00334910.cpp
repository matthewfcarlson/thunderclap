extern "C" int __cdecl allocate(void*, unsigned int);
struct X_334910 {
    int finish();
};
extern "C" int g_value_334910;
int __cdecl target(void* p) {
    g_value_334910 = (int)p;
    X_334910* x = (X_334910*)allocate(p, 0x4c);
    if (x)
        return x->finish();
    return 0;
}
extern "C" int __cdecl allocate(void*, unsigned int);
struct X { int finish(); };
extern "C" int g_value;
int __cdecl target(void* p)
{
    g_value = (int)p;
    X* x = (X*)allocate(p, 0x4c);
    if (x)
        return x->finish();
    return 0;
}
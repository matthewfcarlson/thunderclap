extern "C" void* __cdecl Cast(void*, int, void*, void*, int);
void __cdecl Setup(void* p, int n, int v);
extern char TdA[], TdB[];
inline void Copy(char* d, const char* s) {
    char c;
    do {
        c = *s;
        *d = c;
        s++;
        d++;
    } while (c);
}
class C_931f0 {
  public:
    void* arr[1];
    void F(char* a, int idx, char* name, int v);
    void G(char*, int);
};
struct M_931f0 {
    char pad[0x28];
    char a[8];
    char name[1];
};
void C_931f0::F(char* a, int idx, char* name, int v) {
    M_931f0* o = (M_931f0*)Cast(arr[idx], 0, TdA, TdB, 0);
    if (o) {
        if (name)
            Copy(o->name, name);
        Setup(o->a, 8, v);
        if (*a)
            G(a, idx);
    }
}

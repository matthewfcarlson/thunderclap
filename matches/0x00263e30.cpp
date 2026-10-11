extern char G[];
int __cdecl F1(char*, __int64*);
__int64 __cdecl F2();
void __cdecl F3(char*, void*, __int64*);
class C {
  public:
    char pad[0x10];
    int m10;
    int pad2;
    __int64 m18;
    void Set(int a, __int64* p);
};
void C::Set(int a, __int64* p) {
    m10 = a;
    __int64 v = *p;
    __int64 t = v;
    if (F1(G, &t))
        v = F2();
    m18 = v;
    F3(G, this, &m18);
}

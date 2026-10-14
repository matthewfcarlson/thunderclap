extern void __cdecl ReleaseThing(void*);
extern void* __cdecl Alloc(unsigned int);
extern void __stdcall Init(void*, unsigned int, unsigned int, void(__cdecl*)());
extern void __cdecl ElemCtor();
class Obj_22eda0 {
  public:
    int m0, m1;
    char pad[0x108];
    unsigned int count;
    void* data1;
    void* data2;
    void Target(unsigned int);
};
void Obj_22eda0::Target(unsigned int n) {
    m0 = -1;
    m1 = -1;
    if (count != n) {
        ReleaseThing(data1);
        ReleaseThing(data2);
        data1 = 0;
        data2 = 0;
        count = n;
        if (n > 0) {
            void* p = Alloc(n << 4);
            if (p)
                Init(p, 0x10, n, ElemCtor);
            else
                p = 0;
            data1 = p;
        }
    }
}

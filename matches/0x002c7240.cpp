extern "C" void __cdecl FUN_000c7920();
extern "C" void* __cdecl Alloc(unsigned int);
extern "C" void __stdcall Init(void*, int, int, const float*);
class Obj_2c7240 {
  public:
    char pad[8];
    unsigned int flags;
    int count;
    char pad2[8];
    void* entries[1];
    void Run(int);
};
void Obj_2c7240::Run(int index) {
    if (entries[index] == 0) {
        int n = count;
        void* p = Alloc(n * 8);
        if (p)
            Init(p, 8, n, (const float*)((int)(void (__cdecl*)())&FUN_000c7920));
        else
            p = 0;
        entries[index] = p;
        flags |= 1 << index;
    }
}

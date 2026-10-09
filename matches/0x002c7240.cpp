extern "C" void* __cdecl Alloc(unsigned int);
extern "C" void __stdcall Init(void*, int, int, const float*);
class Obj { public: char pad[8]; unsigned int flags; int count; char pad2[8]; void* entries[1]; void Run(int); };
void Obj::Run(int index) {
    if (entries[index] == 0) {
        int n = count;
        void* p = Alloc(n * 8);
        if (p) Init(p, 8, n, (const float*)0xc7920);
        else p = 0;
        entries[index] = p;
        flags |= 1 << index;
    }
}

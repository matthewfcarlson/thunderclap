struct Result {};
class Obj {
  public:
    char pad[0x14];
    int field;
    void Run(void*);
};
extern Result* __cdecl Find(int, int);
extern void __cdecl SetA(Result*, int*);
extern void __cdecl SetB(Result*, int*);
extern void __cdecl SetC(Result*, int, int);
extern void __cdecl SetD(Result*, int);
void Obj::Run(void* data) {
    Result* r = Find(field, 0);
    if (!r)
        return;
    SetA(r, (int*)(*(char**)((char*)data + 0x3c) + 0x90));
    SetB(r, (int*)(*(char**)((char*)data + 0x3c) + 0x9c));
    int* p = *(int**)((char*)data + 4);
    int* q = *(int**)((char*)p + 0x38);
    SetC(r, q[0], q[1]);
    SetD(r, *(int*)(*(char**)((char*)data + 0x3c) + 0xa8));
}
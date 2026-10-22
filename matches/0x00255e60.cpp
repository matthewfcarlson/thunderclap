struct Result_255e60 {};
class SeqActionClip_255e60 {
  public:
    char pad[0x14];
    int field;
    void Run(void*);
};
extern Result_255e60* __cdecl Find(int, int);
extern void __cdecl SetA(Result_255e60*, int*);
extern void __cdecl SetB(Result_255e60*, int*);
extern void __cdecl SetC(Result_255e60*, int, int);
extern void __cdecl SetD(Result_255e60*, int);
void SeqActionClip_255e60::Run(void* data) {
    Result_255e60* r = Find(field, 0);
    if (!r)
        return;
    SetA(r, (int*)(*(char**)((char*)data + 0x3c) + 0x90));
    SetB(r, (int*)(*(char**)((char*)data + 0x3c) + 0x9c));
    int* p = *(int**)((char*)data + 4);
    int* q = *(int**)((char*)p + 0x38);
    SetC(r, q[0], q[1]);
    SetD(r, *(int*)(*(char**)((char*)data + 0x3c) + 0xa8));
}
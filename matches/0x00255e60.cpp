struct Result_255e60 {};
class SeqActionClip_255e60 {
  public:
    char pad[0x14];
    int field;
    void Run(void*);
};
extern "C" Result_255e60* __cdecl FUN_00258cb0(int, int);
extern "C" void __cdecl FUN_0024cb50(Result_255e60*, int*);
extern "C" void __cdecl FUN_0024cb70(Result_255e60*, int*);
extern "C" void __cdecl FUN_0024c910(Result_255e60*, int, int);
extern "C" void __cdecl FUN_0024c950(Result_255e60*, int);
void SeqActionClip_255e60::Run(void* data) {
    Result_255e60* r = FUN_00258cb0(field, 0);
    if (!r)
        return;
    FUN_0024cb50(r, (int*)(*(char**)((char*)data + 0x3c) + 0x90));
    FUN_0024cb70(r, (int*)(*(char**)((char*)data + 0x3c) + 0x9c));
    int* p = *(int**)((char*)data + 4);
    int* q = *(int**)((char*)p + 0x38);
    FUN_0024c910(r, q[0], q[1]);
    FUN_0024c950(r, *(int*)(*(char**)((char*)data + 0x3c) + 0xa8));
}
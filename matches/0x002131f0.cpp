typedef unsigned int u32;
struct Result {
    int type;
    char* data;
};
extern Result* __fastcall GetResult(void* b, void* a);
extern int __cdecl Check(void* a, Result* b);
u32 __cdecl Target(void* a, void* b) {
    Result* r = GetResult(b, a);
    if (r->type == 4)
        return *(u32*)(r->data + 0x0c);
    if (Check(a, r))
        return *(u32*)(r->data + 0x0c);
    return 0;
}
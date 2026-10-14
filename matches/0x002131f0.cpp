typedef unsigned int u32_2131f0;
struct Result_2131f0 {
    int type;
    char* data;
};
extern Result_2131f0* __fastcall GetResult(void* b, void* a);
extern int __cdecl Check(void* a, Result_2131f0* b);
u32_2131f0 __cdecl Target(void* a, void* b) {
    Result_2131f0* r = GetResult(b, a);
    if (r->type == 4)
        return *(u32_2131f0*)(r->data + 0x0c);
    if (Check(a, r))
        return *(u32_2131f0*)(r->data + 0x0c);
    return 0;
}
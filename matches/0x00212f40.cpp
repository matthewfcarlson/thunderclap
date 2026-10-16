struct Result {
    int kind;
    char* data;
};
extern "C" Result* __fastcall lookup(int a, int b);
int __cdecl check(int a, int b) {
    int t = *(volatile int*)&b;
    Result* p = lookup(t, a);
    if (p->kind == 6 && p->data[6])
        return 1;
    return 0;
}
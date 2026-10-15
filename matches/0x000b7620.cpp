struct Desc {
    int x;
};
extern Desc a, b;
extern "C" int __cdecl find(const char*);
extern "C" char* __cdecl cast(int, int, Desc*, Desc*, int);
void __stdcall FUN_000b7620(char v) {
    char* p = cast(find("mission_success_continue_button"), 0, &a, &b, 0);
    if (p)
        p[0x141] = v;
}
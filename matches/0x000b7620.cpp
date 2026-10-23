struct Desc {
    int x;
};
extern Desc DAT_0049dba4, DAT_0049f4a4;
extern "C" int __cdecl FUN_000fc260(const char*);
extern "C" char* __cdecl FUN_00344e74(int, int, Desc*, Desc*, int);
void __stdcall FUN_000b7620(char v) {
    char* p = FUN_00344e74(FUN_000fc260("mission_success_continue_button"), 0, &DAT_0049dba4, &DAT_0049f4a4, 0);
    if (p)
        p[0x141] = v;
}
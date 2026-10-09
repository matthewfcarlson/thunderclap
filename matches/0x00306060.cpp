typedef int u32;
extern "C" bool __cdecl Check1(u32, u32, u32);
extern "C" char __cdecl Check2(u32, u32, u32);
bool __cdecl Target(u32 a, u32 b, u32 c)
{
    char r = Check1(a, b, c);
    if (r == 0) return false;
    return Check2(a, b, c);
}

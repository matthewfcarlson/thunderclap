unsigned __int64 __cdecl Target(int, int, int);
unsigned __int64 __cdecl Wrapper(int a) {
    return Target(a, 0, 0);
}

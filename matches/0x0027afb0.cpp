int __cdecl Target(int, int, int);
int __cdecl Wrapper(int a) {
    return Target(a, 0, 0);
}

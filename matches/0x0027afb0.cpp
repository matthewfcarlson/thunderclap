void __cdecl Target(int, int, int);
void __cdecl Wrapper(int a) {
    Target(a, 0, 0);
}

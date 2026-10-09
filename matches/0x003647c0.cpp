extern "C" {
int g468;
int g45c;
int g460;
void __cdecl thunk(int);
void __cdecl work(int, int);
void __cdecl FUN_003647c0(void) {
    if (g468 != 0) thunk(g468);
    if (g45c != 0) {
        work(g45c, g460);
        thunk(g45c);
    }
}
}
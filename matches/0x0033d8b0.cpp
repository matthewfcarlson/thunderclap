typedef int(__cdecl* F)(int, int, int);
int __cdecl A(int, int, int);
int __cdecl B(int, int);
int __cdecl C(int, int);
int __cdecl D(int, int);
int __cdecl E(int, int);
int __cdecl G(int, int);
int __cdecl H(int);
void __cdecl target(int p) {
    int x = A(p, 2, 1);
    B(p, 1);
    int y = C(p, 1);
    if (y && x > 0) {
        D(p, x);
        E(p, 1);
        G(p, 2);
    }
    H(p);
}
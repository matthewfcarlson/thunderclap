extern int __cdecl F212d70(int);
extern int __cdecl F339d70(int, int, int);
extern int __cdecl F3392c0(int, int);
extern int __cdecl F339f70(int, int);
extern void __cdecl F339270(int, int, int);
extern void __cdecl F213640(int, int, int);
extern void __cdecl F213870(int, int, int);
extern void __cdecl F212ed0(int, int);
int __cdecl target(int p) {
    int b = F212d70(p);
    F339d70(p, 1, 5);
    int s = F3392c0(p, 1) + 1;
    int e;
    if (b == 2)
        e = s;
    else {
        e = F339f70(p, 2);
        if (e > s)
            s = e;
        b = 3;
    }
    F339270(p, 1, s);
    --s;
    while (s >= e) {
        F213640(p, 1, s);
        F213870(p, 1, s + 1);
        --s;
    }
    F212ed0(p, b);
    F213870(p, 1, e);
    return 0;
}
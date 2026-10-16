void __stdcall Other(int, int);
void __stdcall Target(int n, int unused) {
    if (n >= 0 && n < 0x2fe)
        Other(n, unused);
}
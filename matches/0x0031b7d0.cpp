void __stdcall vfunc_4(char* p) {
    unsigned int* q = (unsigned int*)p;
    q[3] = 10;
    q[0] = 18;
    q[1] = 11;
    q[2] = 56;
    const char* s = "XBox Console";
    char* d = p + 16;
    char c;
    do {
        c = *s;
        *(d - (int)0) = c;
        d++;
        s++;
    } while (c != 0);
}

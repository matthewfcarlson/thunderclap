class A { public: void *p0; int pad[2]; int m3; int pad2[5]; int m9; };
extern const char msg[];
void err(int, const char *);
void f(A *a, int n) { int x = a->m9 + n; if (x > (int)*(unsigned char *)((char *)a->p0 + 0x47)) { if (x >= 250) err(a->m3, msg); *(unsigned char *)((char *)a->p0 + 0x47) = (unsigned char)x; } }
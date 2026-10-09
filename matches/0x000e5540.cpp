extern "C" char *strncpy(char *, const char *, unsigned int);
class C { char pad[0xb80]; public: void f(const char *p); };
void C::f(const char *p) { if (p) strncpy((char*)this + 0xb80, p, 0x40); else *((char*)this + 0xb80) = 0; }
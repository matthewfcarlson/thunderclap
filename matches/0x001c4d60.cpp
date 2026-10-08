extern "C" void * __cdecl memcpy(void *, const void *, unsigned int);
struct X { char pad[0x30]; unsigned int data[16]; void f(unsigned int *); };
void X::f(unsigned int *p) { memcpy(data,p,64); }
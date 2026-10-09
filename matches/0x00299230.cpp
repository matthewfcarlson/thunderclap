typedef unsigned char u8;
struct Obj { char pad[0x0c]; volatile u8* table; void f(u8 index); void g(int v); };
void Obj::f(u8 index) { int value = table[index]; if ((u8)value != 0xff) g(value); }

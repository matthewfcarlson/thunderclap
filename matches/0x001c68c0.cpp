typedef unsigned char u8;
struct Caller { void method(int); };
struct Obj { char pad[8]; u8 enabled; char pad9[7]; int value; void target(Caller* arg); };
void Obj::target(Caller* arg) { if (enabled && value) arg->method(value); }
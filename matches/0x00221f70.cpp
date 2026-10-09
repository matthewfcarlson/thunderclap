class Obj2 { public: char pad[0x40]; void callee1(int, int); };
class Obj { public: char pad[0x50]; int state; void run(int, int); void callee2(int, int); };
void Obj::run(int a, int b) {
 switch (state) {
 case 0:
 case 2: return callee2(a, b);
 case 1: return ((Obj2*)((char*)this + 0x40))->callee1(a, b);
 }
}

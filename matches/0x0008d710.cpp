extern "C" unsigned char flag;
extern "C" void __cdecl InitA();
extern "C" void __cdecl InitC(int);
extern "C" void __cdecl DoThing(int,int);
struct Obj { char pad[0x80]; void InitB(); };
extern Obj object;
void __cdecl Target(int a,int b) {
 if (!flag) { InitA(); object.InitB(); InitC(30); flag=1; }
 DoThing(b,a);
}

struct CSoundStreamAllocator { virtual void f0(); virtual void vfunc_1(int a, int b); };
extern int __cdecl FUN_0024b030(int);
extern int __cdecl FUN_0024c590(int,int);
extern int __cdecl FUN_0026fd50(int,int);
struct Receiver { void run(int); };
extern Receiver* receiver;
extern void __cdecl FUN_0024bf90(int);
int g800=0x800;
void CSoundStreamAllocator::vfunc_1(int a, int c) {
 int x=FUN_0024b030(c);
 x=FUN_0024c590(x,3000);
 x=FUN_0026fd50(x,g800);
 receiver->run(x);
 FUN_0024bf90(c);
}
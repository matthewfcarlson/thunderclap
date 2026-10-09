typedef unsigned char u8; typedef unsigned int u32;
struct Obj { char pad[8]; int member; bool run(u32 arg, u8 flag); };
void f1(int, u32); void f2(int,int,int); void f3(int,int);
bool Obj::run(u32 arg, u8 flag) {
 int v = -3;
 if (flag) v = -10001;
 f1(member,arg); f2(member,0,0); f3(member,v); return true;
}

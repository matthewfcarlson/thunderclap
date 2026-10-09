typedef unsigned int u32; typedef unsigned char u8;
struct Item { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void n(); };
class CMotionTrailQueue { public: char pad[0x48]; char* items; char pad2[0x0c]; u32 state; u8* bytes; void vfunc_9(); };
void CMotionTrailQueue::vfunc_9() { int i = 0; state = 1; for (int j=0; j<0x60; j+=0x10, i+=8) { (*(Item**)(items+j))->n(); bytes[i+4]=0; } }
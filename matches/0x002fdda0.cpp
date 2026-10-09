namespace physics {
class SimState { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void vfunc_8(int,int,int); char pad[0x88]; };
struct Part { char data[0x64]; void call(int,int); };
class SimStateArticulated : public SimState { public: Part* parts; void vfunc_8(int a,int b,int index); };
void SimStateArticulated::vfunc_8(int a,int b,int index) {
 if(index >= 0) parts[index].call(a,b);
 else SimState::vfunc_8(a,b,-1);
}
}
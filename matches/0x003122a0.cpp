class Helper { public: void Init(); };
class ArticulatedPhysicsObject {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual ArticulatedPhysicsObject* f28(unsigned int);
 char pad[0x20];
 void Setup(void*, unsigned int);
};
extern "C" void* __cdecl alloc(unsigned int);
ArticulatedPhysicsObject* ArticulatedPhysicsObject::f28(unsigned int a) {
 void* p=alloc(0x238);
 if(p) {
  ((Helper*)p)->Init();
  *(unsigned int*)p=0x43217c;
  *(unsigned int*)((char*)p+0x1fc)=0;
  *(unsigned int*)((char*)p+0x24)=1;
 } else { p=0; }
 Setup(p,a);
 *(unsigned int*)((char*)p+0x24)=*(unsigned int*)((char*)this+0x24);
 return (ArticulatedPhysicsObject*)p;
}
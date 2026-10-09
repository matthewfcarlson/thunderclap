class Entity { public: virtual void a(); virtual void b(); };
class Sequence : public Entity { public: virtual void c(); virtual void d(); virtual void vfunc_4(unsigned int); virtual void e(unsigned int); virtual void f(); virtual void g(); virtual void h(); };
void InitA(void*);
void InitB(void*);
void Sequence::vfunc_4(unsigned int p) {
  *(void**)((char*)this + 0x28) = (char*)this + 0x2c;
  InitA((char*)this + 0x3c);
  InitB((char*)this + 0x44);
  e(p);
}
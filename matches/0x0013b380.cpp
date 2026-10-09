class Service { public: Service* get(); Service* check(); void run(void*, int, float); };
class AnimationLinkedAction { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void vfunc_4(); virtual void e(); char pad[0x1c]; Service* m20; void* m24; };
struct Obj { virtual void a(); virtual void b(); };
void AnimationLinkedAction::vfunc_4() { if(m24) { Service* x=m20->get(); Service* y=x->check(); if(y) { y->run(m24,0,-1.0f); if(m24) { ((Obj*)m24)->b(); m24=0; } } } }
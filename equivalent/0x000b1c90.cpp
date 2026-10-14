// STATUS: equivalent (tools/equiv.py level 3: 1691 inputs, branch coverage 22/22)
// FUN_000b1c90 @ 0x000b1c90
void* __cdecl FUN_0008d710(unsigned size, int alignment);
void* __cdecl FUN_0008d750(unsigned size, int alignment);
void __cdecl FUN_0008d330(void*);
inline void* operator new(unsigned, void* p) { return p; }
struct Controller_b1c90;
struct State_b1c90 { int first; int middle; int last; };
struct sControllerInputPointCallback;
struct Point_b1c90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
 virtual void attach(sControllerInputPointCallback*, int);
};
struct Device_b1c90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual int count(const char*);
 virtual Point_b1c90* point(const char*, int);
};
struct sControllerInputPointCallback {
 virtual void callback();
 Point_b1c90* point;
 Controller_b1c90* controller;
 State_b1c90* state;
};
struct Controller_b1c90 {
 char pad0[0x10]; Device_b1c90* device;
 char pad1[0x40]; int id;
 char pad2[0x450]; sControllerInputPointCallback** callbacks;
 void FUN_000b1c90(State_b1c90*, int);
};
void Controller_b1c90::FUN_000b1c90(State_b1c90* state, int requested) {
 if (id != requested || !device) return;
 state->first = 0;
 state->last = 0;
 int n = device->count("Button");
 if (callbacks) {
  for (int i=0; i<n; ++i) {
   if (callbacks[i]) {
    FUN_0008d330(callbacks[i]);
    callbacks[i] = 0;
   }
  }
 }
 if (callbacks) {
  FUN_0008d330(callbacks);
  callbacks = 0;
 }
 callbacks = (sControllerInputPointCallback**)FUN_0008d750((unsigned)n*4,4);
 for (int i=0; i<n; ++i) {
  Point_b1c90* p = device->point("Button",i);
  if (p) {
   void* storage = FUN_0008d710(16,4);
   sControllerInputPointCallback* c = 0;
   if (storage) {
    c = new(storage) sControllerInputPointCallback;
    c->point = p;
    c->controller = this;
    c->state = state;
   }
   callbacks[i] = c;
   p->attach(callbacks[i],0);
  }
 }
}

// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 12/12)
// core::ControllerXBox::vfunc_19 @ 0x002686d0
namespace core {
struct Event { unsigned first; unsigned second; char rest[16]; };
struct Input {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 virtual unsigned char vfunc_6(void **, unsigned); virtual unsigned char vfunc_7(Event *);
};
struct Listener {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
 virtual void vfunc_14(void *, unsigned *);
 char padding[0x30];
};
struct ControllerXBox {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18();
 virtual void vfunc_19(unsigned);
 unsigned active; char pad0[0xc]; unsigned listenerCount; Listener listeners[1]; char pad1[0x454 - 0x18 - 0x34]; Input *input;
};
void ControllerXBox::vfunc_19(unsigned unused) {
 if (!active) return;
 void *item = 0;
 if (!input->vfunc_6(&item,4)) return;
 Event event;
 do {
  if (input->vfunc_7(&event) != 1) break;
  for (unsigned i = 0; i < listenerCount; ++i)
   listeners[i].vfunc_14(item,&event.second);
 } while (input->vfunc_6(&item,4));
}
}
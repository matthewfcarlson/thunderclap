// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_000819f0 @ 0x000819f0
namespace pure3d { class Animation; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual T* cast(void*); }; }; }
struct Track { void* FUN_00288960(unsigned, unsigned); };
namespace pure3d { class Animation { public: Track* FUN_00288a20(int); }; }
struct Inventory { virtual void v0(); virtual void v1(); virtual void v2(); virtual pure3d::Animation* find(content::LoadInventory::DynamicCaster<pure3d::Animation>*, unsigned, unsigned); };
struct Resource { Inventory* FUN_00203d70(); };
struct Manager { Resource* FUN_000862a0(); };
struct Globals { char pad[0x54]; Manager* manager; };
extern Globals* DAT_004dd700;
struct Controller {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
virtual void setValue(unsigned);
virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
virtual void setMode(int);
virtual void v17(); virtual void setEnabled(int); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
virtual void setAnimation(pure3d::Animation*, unsigned, unsigned);
char pad[0x144]; unsigned state;
};
struct Object {
char pad0[0x10]; int mode1; int mode2; char pad18[0x10]; unsigned flags; unsigned counter; float time; char pad34[0xbc]; Controller* controller; Track* track; void* translation; void* rotation;
void FUN_000819f0(unsigned a, unsigned b, unsigned c, float d, unsigned e, unsigned f, unsigned g);
};
void Object::FUN_000819f0(unsigned a,unsigned b,unsigned c,float d,unsigned e,unsigned f,unsigned g) {
Inventory* inventory = DAT_004dd700->manager->FUN_000862a0()->FUN_00203d70();
content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
pure3d::Animation* anim = inventory->find(&caster,a,b);
if (!anim) return;
mode1=6; mode2=6; counter=0;
track=anim->FUN_00288a20(0);
if(track) { translation=track->FUN_00288960(0x4e415254,0x54434556); rotation=track->FUN_00288960(0x544f52,0x544f52); }
else { translation=0; rotation=0; }
controller->setAnimation(anim,e,g);
controller->setMode(2);
controller->setValue(c);
controller->setEnabled((unsigned char)f ? 0:1);
controller->state=0;
flags &= ~8u;
if(d>0.0f) time=d;
}

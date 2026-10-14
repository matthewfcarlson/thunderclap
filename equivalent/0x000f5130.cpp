// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_000f5130 @ 0x000f5130
namespace pure3d { struct MultiController { virtual void Activate(); }; struct Scenegraph; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual T* Cast(void*); }; }; }
typedef unsigned __int64 Key_f5130;
Key_f5130 __cdecl FUN_0027b020(const char*);
struct Inventory_f5130 { virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual pure3d::MultiController* Find(void*, Key_f5130); };
extern Inventory_f5130* DAT_004dd9cc;
void __cdecl FUN_000f6410(pure3d::MultiController*, void*);
struct Object { char pad[0x1c64]; pure3d::MultiController* controllers[2]; char gap[8]; char names[2][256]; char gap2[0x2105-0x1e74]; char name[1]; void Run(const char*, const char*); };
void Object::Run(const char* a, const char* b) {
 int i; for(i=0;i<2;++i) if(!controllers[i]) break;
 if(i==2) return;
 Inventory_f5130* inv=DAT_004dd9cc;
 Key_f5130 key=FUN_0027b020(a);
 content::LoadInventory::DynamicCaster<pure3d::MultiController> caster;
 pure3d::MultiController* c=inv->Find(&caster,key);
 controllers[i]=c;
 if(!c) return;
 c->Activate();
 if(b) {
 inv=DAT_004dd9cc;
 key=FUN_0027b020(b);
 content::LoadInventory::DynamicCaster<pure3d::Scenegraph> sceneCaster;
 void* scene=inv->Find(&sceneCaster,key);
 if(!scene) return;
 FUN_000f6410(controllers[i],scene);
 }
 char* dst=names[i]; const char* src=name;
 do { *dst=*src; ++dst; } while(*src++);
}
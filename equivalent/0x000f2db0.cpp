// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 11/12, incomplete)
// FUN_000f2db0 @ 0x000f2db0
#include "decls/address.h"
struct MultiController {
 virtual void Start();
 virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void Mode(int);
};
namespace pure3d { struct MultiController; namespace scenegraph { struct Scenegraph; } }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void * Cast(void *); }; } }
struct Inventory_f2db0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual MultiController *Find(void *, unsigned int, unsigned int); };
extern Inventory_f2db0 *DAT_004dd9cc;
extern void __cdecl FUN_000f6410(MultiController *, MultiController *);
struct Target_f2db0 { char pad[0x9b4]; MultiController *controllers[4]; void run(const char *,const char *); };
void Target_f2db0::run(const char *name,const char *scene) {
 int i; for(i=0;i<4;++i) if(!controllers[i]) break;
 if(i==4) return;
 Inventory_f2db0 *inv=DAT_004dd9cc;
 unsigned __int64 key=FUN_0027b020(name);
 content::LoadInventory::DynamicCaster<pure3d::MultiController> caster;
 MultiController *p=inv->Find(&caster,(unsigned)key,(unsigned)(key>>32));
 controllers[i]=p;
 if(!p) return;
 p->Start();
 controllers[i]->Mode(2);
 if(scene) {
 inv=DAT_004dd9cc;
 key=FUN_0027b020(scene);
 content::LoadInventory::DynamicCaster<pure3d::scenegraph::Scenegraph> caster2;
 p=inv->Find(&caster2,(unsigned)key,(unsigned)(key>>32));
 if(p) FUN_000f6410(controllers[i],p);
 }
}

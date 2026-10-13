// STATUS: equivalent (tools/equiv.py level 3: 385 inputs, branch coverage 10/10)
// FUN_0007e570 @ 0x0007e570
namespace pure3d { struct CompositeDrawable; }
namespace content { template<class T> struct LoadInventoryDynamicCaster; struct LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; }; }
struct Item { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void update(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void set(float,float); };
struct Group { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int count(); virtual void v17(); virtual Item* get(int); };
struct Entry { int a,b; Group* group; };
struct List { char pad[0x3c]; Entry* begin; Entry* end; };
namespace pure3d { struct CompositeDrawable { virtual void prepare(); char pad[0x40]; List* list; }; }
struct Result { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual pure3d::CompositeDrawable* drawable(); };
struct Inventory { virtual void v0(); virtual void v1(); virtual void v2(); virtual Result* find(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>*,int,int); };
struct Context { Inventory* FUN_00203d70(); };
struct Service { Context* FUN_000862a0(); };
struct Holder { char pad[0x54]; Service* service; };
struct Key { int first,second; };
struct Target { char pad[0x382c]; Holder* holder; pure3d::CompositeDrawable* run(Key*,int); };
pure3d::CompositeDrawable* Target::run(Key* key,int value) {
 Inventory* inv=holder->service->FUN_000862a0()->FUN_00203d70();
 content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
 Result* result=inv->find(&caster,key->first,key->second);
 if(!result) return 0;
 pure3d::CompositeDrawable* object=result->drawable();
 object->prepare();
 float f=(float)value;
 List* list=object->list;
 int count=(unsigned char)(list->end-list->begin);
 for(int i=0;i<count;++i) {
 Group* group=list->begin[(unsigned char)i].group;
 int n=group->count();
 for(int j=0;j<n;++j) {
 group->get(j)->set(f,f);
 group->get(j)->update();
 }
 }
 return object;
}
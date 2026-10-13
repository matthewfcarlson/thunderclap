// STATUS: equivalent (tools/equiv.py level 3: 34 inputs, branch coverage 31/34, incomplete)
// FUN_0027e2d0 @ 0x0027e2d0
struct Ref { virtual void slot0(); virtual void release(); };
struct Item : Ref { char pad[0xc]; unsigned key; char pad2[0x60]; unsigned handle; };
struct State { char pad[0x2c]; int count; };
struct Data : Ref { char pad[0x18]; State **begin; State **end; };
struct Entry { unsigned unused[4]; Item *object; Ref *extra; };
struct Attachment { Ref *object; unsigned unused[2]; };
struct Manager { void FUN_002eecb0(unsigned); void FUN_002ee700(Item*); };
extern Manager *DAT_00554c14;
struct Registry { void FUN_002834b0(unsigned); };
extern Registry *__cdecl FUN_0027f250();
extern void __cdecl FUN_0008d330(void*);
extern void __cdecl FUN_0008d340(void*);
struct Base { virtual void slot0(); void FUN_002a35f0(); };
namespace pure3d { namespace prop {
struct StateProp : Base {
 virtual void slot0();
 ~StateProp();
 char pad0[0x3c]; int stateIndex; char pad1[0x44]; Ref *resource; char pad2[0xc]; Data *data; Ref *other1; Ref *other2; Entry *entries; unsigned entryCount; Item **items; unsigned unknown; int attachmentCount; Attachment attachments[1];
};
StateProp::~StateProp() {
 int count = data->begin[stateIndex]->count;
 for(int i=0;i<count;++i) {
  Entry *e=entries+i;
  if(e->object) {
   DAT_00554c14->FUN_002eecb0(e->object->handle);
   e->object->release();
   if(e->extra) e->extra->release();
  }
 }
 for(int j=0;j < data->end-data->begin;++j) {
  if(items[j]) {
   Registry *r=FUN_0027f250();
   if(r) r->FUN_002834b0(items[j]->key);
   if(DAT_00554c14) DAT_00554c14->FUN_002ee700(items[j]);
  }
  Item **p=items+j;
  if(*p) { (*p)->release(); *p=0; }
 }
 FUN_0008d330(items);
 for(int k=0;k<attachmentCount;++k) {
  Attachment *a=attachments+k;
  if(a->object) { a->object->release(); a->object=0; }
 }
 unsigned bytes=entryCount*24u;
 unsigned *words=(unsigned*)entries;
 for(unsigned n=0;n<(bytes>>2);++n) words[n]=0;
 FUN_0008d340(entries);
 if(resource) { resource->release(); resource=0; }
 if(data) { data->release(); data=0; }
 if(other1) { other1->release(); other1=0; }
 if(other2) { other2->release(); other2=0; }
 FUN_002a35f0();
}
}}

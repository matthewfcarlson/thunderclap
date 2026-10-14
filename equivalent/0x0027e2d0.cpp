// STATUS: equivalent (tools/equiv.py level 3: 34 inputs, branch coverage 31/34, incomplete)
// FUN_0027e2d0 @ 0x0027e2d0
struct Ref_27e2d0 { virtual void slot0(); virtual void release(); };
struct Item_27e2d0 : Ref_27e2d0 { char pad[0xc]; unsigned key; char pad2[0x60]; unsigned handle; };
struct State_27e2d0 { char pad[0x2c]; int count; };
struct Data_27e2d0 : Ref_27e2d0 { char pad[0x18]; State_27e2d0 **begin; State_27e2d0 **end; };
struct Entry_27e2d0 { unsigned unused[4]; Item_27e2d0 *object; Ref_27e2d0 *extra; };
struct Attachment_27e2d0 { Ref_27e2d0 *object; unsigned unused[2]; };
struct Manager_27e2d0 { void FUN_002eecb0(unsigned); void FUN_002ee700(Item_27e2d0*); };
extern Manager_27e2d0 *DAT_00554c14;
struct Registry_27e2d0 { void FUN_002834b0(unsigned); };
extern Registry_27e2d0 *__cdecl FUN_0027f250();
extern void __cdecl FUN_0008d330(void*);
extern void __cdecl FUN_0008d340(void*);
struct Base_27e2d0 { virtual void slot0(); void FUN_002a35f0(); };
namespace pure3d { namespace prop {
struct StateProp : Base_27e2d0 {
 virtual void slot0();
 ~StateProp();
 char pad0[0x3c]; int stateIndex; char pad1[0x44]; Ref_27e2d0 *resource; char pad2[0xc]; Data_27e2d0 *data; Ref_27e2d0 *other1; Ref_27e2d0 *other2; Entry_27e2d0 *entries; unsigned entryCount; Item_27e2d0 **items; unsigned unknown; int attachmentCount; Attachment_27e2d0 attachments[1];
};
StateProp::~StateProp() {
 int count = data->begin[stateIndex]->count;
 for(int i=0;i<count;++i) {
  Entry_27e2d0 *e=entries+i;
  if(e->object) {
   DAT_00554c14->FUN_002eecb0(e->object->handle);
   e->object->release();
   if(e->extra) e->extra->release();
  }
 }
 for(int j=0;j < data->end-data->begin;++j) {
  if(items[j]) {
   Registry_27e2d0 *r=FUN_0027f250();
   if(r) r->FUN_002834b0(items[j]->key);
   if(DAT_00554c14) DAT_00554c14->FUN_002ee700(items[j]);
  }
  Item_27e2d0 **p=items+j;
  if(*p) { (*p)->release(); *p=0; }
 }
 FUN_0008d330(items);
 for(int k=0;k<attachmentCount;++k) {
  Attachment_27e2d0 *a=attachments+k;
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

// STATUS: equivalent (tools/equiv.py level 3: 178 inputs, branch coverage 10/10)
// FUN_002a4b00 @ 0x002a4b00
struct Object { virtual void retain(); virtual void release(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void attach(unsigned value); };
struct Reader;
struct Factory { virtual void retain(); virtual void release(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void create(Object** out, unsigned* auxiliary, Reader* reader, unsigned arg); };
struct Source { void FUN_002647e0(unsigned* out, unsigned a, unsigned b, unsigned c); };
struct Reader { char pad[0x284]; Source* source; bool FUN_002669f0(); unsigned FUN_00266a30(); void FUN_00266be0(); };
struct Collection { unsigned owner; Object** begin; Object** end; };
struct Manager { void* FUN_00265310(unsigned id); };
extern Manager* DAT_00527c58;
extern unsigned DAT_004ce770, DAT_0049c7dc;
extern Factory* __cdecl FUN_00344e74(void*, unsigned, unsigned*, unsigned*, unsigned);
struct Target { void FUN_002a4a50(Collection*, unsigned); void work(Collection* collection, Reader* reader, unsigned arg); };
void Target::work(Collection* collection, Reader* reader, unsigned arg) {
 unsigned count;
 reader->source->FUN_002647e0(&count,1,4,1);
 unsigned size = (unsigned)(collection->end - collection->begin);
 reader->source->FUN_002647e0(&count,1,4,1);
 FUN_002a4a50(collection,count+size);
 Factory* factory = FUN_00344e74(DAT_00527c58->FUN_00265310(0x121201),0,&DAT_0049c7dc,&DAT_004ce770,0);
 factory->retain();
 if(reader->FUN_002669f0()) {
 unsigned offset=size;
 do {
 if(reader->FUN_00266a30()==0x121201) {
 Object* object=0; unsigned aux;
 factory->create(&object,&aux,reader,arg);
 Object** slot=collection->begin+offset;
 Object* saved=object;
 if(object) object->retain();
 if(*slot) (*slot)->release();
 *slot=saved;
 object->attach(collection->owner);
 ++offset;
 }
 reader->FUN_00266be0();
 } while(reader->FUN_002669f0());
 }
 factory->release();
}
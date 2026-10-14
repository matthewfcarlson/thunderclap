// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 12/12)
// FUN_002d1090 @ 0x002d1090
struct Object { virtual void AddRef(); virtual void Release(); virtual void v2(); virtual void v3(); virtual void v4(); virtual unsigned Type(); };
struct Entry_2d1090 { Object* object; char pad[12]; };
struct Source_2d1090 { char pad[0x48]; Entry_2d1090* begin; Entry_2d1090* end; char gap[8]; Object* animation; };
namespace pure3d { class VertexAnimObject; }
struct InitContext { unsigned offset; pure3d::VertexAnimObject* owner; };
struct Storage_2d1090 { Object** data; unsigned other; void FUN_002d0eb0(unsigned count, InitContext* context); };
namespace pure3d {
class VertexAnimObject { public: virtual void v0(); unsigned field4; Object* animation; Storage_2d1090 storage; VertexAnimObject* Initialize(Source_2d1090* source); };
VertexAnimObject* VertexAnimObject::Initialize(Source_2d1090* source) {
 this->VertexAnimObject::VertexAnimObject();
 field4=0; animation=0; storage.data=0; storage.other=0;
 unsigned count=(unsigned)(((int)((char*)source->end-(char*)source->begin)) >> 4);
 InitContext context; context.offset=0; context.owner=this;
 storage.FUN_002d0eb0(count,&context);
 VertexAnimObject* current=this;
 if(count) context.offset=0;
 for(unsigned i=0;i<count;++i) {
  Object* obj=source->begin[context.offset/16].object;
  if(obj->Type()==0x40) {
   Object** slot=current->storage.data+i;
   obj->AddRef();
   if(*slot) (*slot)->Release();
   *slot=obj;
   current=context.owner;
  }
  context.offset+=16;
 }
 Object* obj=source->animation;
 if(obj) obj->AddRef();
 if(current->animation) current->animation->Release();
 current->animation=obj;
 return current;
}
}
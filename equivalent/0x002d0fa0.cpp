// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 12/12)
// FUN_002d0fa0 @ 0x002d0fa0
struct RefObject_2d0fa0 {
 virtual void AddRef();
 virtual void Release();
 virtual void Slot2();
 virtual void Slot3();
 virtual void Slot4();
 virtual unsigned Type();
};
struct Entry_2d0fa0 { RefObject_2d0fa0* object; char padding[12]; };
struct Source_2d0fa0 { char padding[0x48]; Entry_2d0fa0* begin; Entry_2d0fa0* end; char gap[0x14]; RefObject_2d0fa0* extra; };
struct Array_2d0fa0 { RefObject_2d0fa0** data; unsigned size; void FUN_002d0eb0(unsigned count, unsigned* zero); };
namespace pure3d {
struct VertexAnimObject {
 virtual void Slot0();
 unsigned field4;
 RefObject_2d0fa0* extra;
 Array_2d0fa0 entries;
 VertexAnimObject(Source_2d0fa0* source);
};
}
pure3d::VertexAnimObject::VertexAnimObject(Source_2d0fa0* source) {
 field4=0;
 extra=0;
 entries.data=0;
 entries.size=0;
 unsigned count=(unsigned)(((char*)source->end-(char*)source->begin)>>4);
 unsigned zero=0;
 entries.FUN_002d0eb0(count,&zero);
 for(unsigned i=0;i<count;++i) {
 RefObject_2d0fa0* object=source->begin[i].object;
 if(object->Type()==0x40) {
 RefObject_2d0fa0** slot=entries.data+i;
 object->AddRef();
 if(*slot) (*slot)->Release();
 *slot=object;
 }
 }
 RefObject_2d0fa0* value=source->extra;
 if(value) value->AddRef();
 if(extra) extra->Release();
 extra=value;
}
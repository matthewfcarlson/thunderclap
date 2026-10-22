// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_002c3060 @ 0x002c3060
namespace pure3d { struct Geometry; }
struct Ref_2c3060 {
 virtual void AddRef();
 virtual void Release();
 virtual void slot2();
 virtual void slot3();
 virtual Ref_2c3060* Clone();
 virtual void SetOwner(pure3d::Geometry*);
 void FUN_002a6930(pure3d::Geometry*);
};
struct VertexAnimObject_2c3060 : Ref_2c3060 { VertexAnimObject_2c3060* FUN_002d1090(pure3d::Geometry*); };
void* __cdecl FUN_0008d690(unsigned int);
struct DrawableContainer_2c3060 {
 virtual void slot0();
 char padding[0x54];
 DrawableContainer_2c3060(pure3d::Geometry*);
};
namespace pure3d {
struct Geometry : DrawableContainer_2c3060 {
 Ref_2c3060* resource;
 VertexAnimObject_2c3060* helper;
 Ref_2c3060* first;
 Ref_2c3060* second;
 virtual void slot0();
 Geometry(Geometry* source);
};
Geometry::Geometry(Geometry* source) : DrawableContainer_2c3060(source) {
 resource=0; helper=0; first=0; second=0;
 Ref_2c3060* r=source->resource;
 if(r) r->AddRef();
 if(resource) resource->Release();
 resource=r;
 if(source->helper) {
  VertexAnimObject_2c3060* h=(VertexAnimObject_2c3060*)FUN_0008d690(0x18);
  if(h) h=h->FUN_002d1090(this);
  helper=h;
  h->AddRef();
 }
 if(source->first) {
  r=source->first->Clone();
  if(r) r->AddRef();
  if(first) first->Release();
  first=r;
  if(r) r->SetOwner(this);
 }
 if(source->second) {
  r=source->second->Clone();
  if(r) r->AddRef();
  if(second) second->Release();
  second=r;
  if(r) r->FUN_002a6930(this);
 }
}
}

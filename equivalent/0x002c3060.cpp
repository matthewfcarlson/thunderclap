// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_002c3060 @ 0x002c3060
namespace pure3d { struct Geometry; }
struct Ref {
 virtual void AddRef();
 virtual void Release();
 virtual void slot2();
 virtual void slot3();
 virtual Ref* Clone();
 virtual void SetOwner(pure3d::Geometry*);
 void FUN_002a6930(pure3d::Geometry*);
};
struct Helper : Ref { Helper* FUN_002d1090(pure3d::Geometry*); };
void* __cdecl FUN_0008d690(unsigned int);
struct Base {
 virtual void slot0();
 char padding[0x54];
 Base(pure3d::Geometry*);
};
namespace pure3d {
struct Geometry : Base {
 Ref* resource;
 Helper* helper;
 Ref* first;
 Ref* second;
 virtual void slot0();
 Geometry(Geometry* source);
};
Geometry::Geometry(Geometry* source) : Base(source) {
 resource=0; helper=0; first=0; second=0;
 Ref* r=source->resource;
 if(r) r->AddRef();
 if(resource) resource->Release();
 resource=r;
 if(source->helper) {
  Helper* h=(Helper*)FUN_0008d690(0x18);
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

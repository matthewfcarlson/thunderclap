// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002e0760 @ 0x002e0760
typedef unsigned size_t;
inline void* __cdecl operator new(size_t, void* address) { return address; }
struct Ref { virtual void AddRef(); virtual void Release(); };
struct Six { unsigned a[6]; }; struct Four { unsigned a[4]; };
struct Source { virtual void AddRef(); virtual void Release(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual Ref* GetRef(); char pad[12]; unsigned type; Six six; Four four; unsigned field3c; Ref* resource; unsigned value44; unsigned value48; unsigned value4c; unsigned FUN_002a50b0(); };
namespace pure3d { struct VertexAnimPrimGroup { virtual void slot0(); char pad[12]; unsigned type; Six six; Four four; unsigned field3c; Ref* resource; unsigned value44; unsigned value48; unsigned value4c; unsigned value50; unsigned value54; Source* source; unsigned value5c; void FUN_002a5060(); VertexAnimPrimGroup* init(Source* other); }; }
pure3d::VertexAnimPrimGroup* pure3d::VertexAnimPrimGroup::init(Source* other) { unsigned a=other->value48, b=other->value4c; FUN_002a5060(); resource=0; value44=0; value48=a; value4c=b; value50=~0u; new (this) VertexAnimPrimGroup(*this); source=0; value5c=0; type=other->FUN_002a50b0(); Six s=other->six; six=s; Four f=other->four; four=f; value44=other->value44; Ref* r=other->GetRef(); if(r) r->AddRef(); if(resource) resource->Release(); resource=r; other->AddRef(); if(source) source->Release(); source=other; return this; }
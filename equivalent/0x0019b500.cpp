// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0019b500 @ 0x0019b500
void* __cdecl operator new(unsigned int);
struct Ref { virtual void AddRef(); virtual void Release(); };
struct FUN_00232660 { virtual void baseSlot(); char pad[24]; FUN_00232660(); };
namespace hulkfight { namespace motion {
struct BeamEffect {
 virtual void slot0();
 int owner; int a8,aC,a10,a14,a18,a1C,a20,a24,a28; float a2C; int a30;
};
struct FireBeamAction : FUN_00232660 {
 int owner; Ref* ref; int a24,a28,a2C,a30,a34,a38,a3C; char pad40[12]; int a4C,a50; char pad54[12]; int a60,a64; BeamEffect* effect; char pad6C[24]; int a84,a88; float a8C;
 virtual void baseSlot();
 FireBeamAction(int,Ref*);
};
FireBeamAction::FireBeamAction(int o,Ref* r) {
 owner=0; ref=0; a30=0; a34=0; a38=0; a3C=0; a4C=0; a50=0; a60=0; a64=0; effect=0; a84=0; a88=0; a8C=-1.0f;
 owner=o;
 if(r) r->AddRef();
 if(ref) ref->Release();
 ref=r; a2C=0; a28=0; a24=0;
 BeamEffect* e=new BeamEffect;
 if(e) { e->owner=o; e->a8=0;e->aC=0;e->a10=0;e->a14=0;e->a18=0;e->a1C=0;e->a20=0;e->a24=0;e->a28=0;e->a2C=-1.0f;e->a30=0; }
 effect=e;
}
}}

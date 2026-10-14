// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00290b30 @ 0x00290b30
struct Ref_290b30 { virtual void AddRef(); virtual void Release(); char pad[4]; unsigned a,b; };
struct Pair_290b30 { unsigned a,b; void FUN_0027af60(unsigned,unsigned); };
struct Storage_290b30 { unsigned a,b,c; void FUN_00290790(unsigned, unsigned*); };
struct Tail_290b30 { unsigned a,b; void FUN_00290ad0(unsigned); };
struct FUN_0027b070 { virtual void slot0(); char pad[4]; FUN_0027b070(); };
namespace pure3d { namespace prop {
struct StatePropData : FUN_0027b070 {
 virtual void slot0();
 Pair_290b30 data;
 Ref_290b30 *first,*second,*third;
 Storage_290b30 storage;
 Tail_290b30 tail;
 StatePropData(Ref_290b30*,Ref_290b30*,Ref_290b30*,unsigned,unsigned);
};
StatePropData::StatePropData(Ref_290b30* p,Ref_290b30* q,Ref_290b30* r,unsigned x,unsigned y) {
 first=0; second=0; third=0; storage.a=0; storage.b=0; tail.a=0; tail.b=0;
 data.FUN_0027af60(p->a,p->b);
 p->AddRef();
 if(first) first->Release();
 first=p;
 if(q) q->AddRef();
 if(second) second->Release();
 second=q;
 if(r) r->AddRef();
 if(third) third->Release();
 third=r;
 unsigned zero=0;
 storage.FUN_00290790(x,&zero);
 tail.FUN_00290ad0(y);
}
} }

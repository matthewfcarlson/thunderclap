// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 16/16)
// FUN_00290910 @ 0x00290910
struct Ref_290910 { virtual void slot0(); virtual void release(); };
void __cdecl FUN_00290500(void*, unsigned);
void __cdecl FUN_0008d340(void*);
struct Base_290910 { virtual void slot0(); char pad[12]; void FUN_0027afd0(); };
namespace pure3d { namespace prop {
struct StatePropData : Base_290910 {
 Ref_290910* a; Ref_290910* b; Ref_290910* c; Ref_290910** begin; Ref_290910** end; Ref_290910** capacity; void* data; unsigned count;
 virtual ~StatePropData();
};
}}
pure3d::prop::StatePropData::~StatePropData() {
 if(a) { a->release(); a=0; }
 if(b) { b->release(); b=0; }
 if(c) { c->release(); c=0; }
 for(unsigned i=0; i<(unsigned)(end-begin); ++i) {
  Ref_290910** entry=begin+i;
  if(*entry) { (*entry)->release(); *entry=0; }
 }
 if(data) { FUN_00290500(data,count); FUN_0008d340(data); }
 if(begin) FUN_0008d340(begin);
 FUN_0027afd0();
}

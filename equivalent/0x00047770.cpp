// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 12/12)
// CCharacterTemplateManager::vfunc_0 @ 0x00047770
struct Context { char pad[32]; void* data; };
struct Node { char pad[24]; char name[21]; void FUN_0027aac0(const char*, const char**); };
struct Template_47770 { virtual void retain(); virtual void release(); Template_47770* FUN_00045840(); void FUN_000464c0(void*, Node*); };
extern unsigned __int64 __cdecl FUN_0027b020(const char*);
extern void* __cdecl FUN_0008d690(unsigned);
struct RDLHandler { virtual void vfunc_0(Context*,Node*); virtual void vfunc_1(); };
struct CCharacterTemplateManager : RDLHandler { int unknown; int capacity; int count; Template_47770** entries; Template_47770* FUN_00044ad0(unsigned __int64); virtual void vfunc_0(Context*,Node*); };
void CCharacterTemplateManager::vfunc_0(Context* context, Node* node) {
 void* data=context->data;
 const char* expected="RdlCharacterTemplate";
 for(int i=0;i<21;++i) { if(node->name[i]!=expected[i]) return; }
 const char* variation=0;
 node->FUN_0027aac0("VariationName", &variation);
 Template_47770* item=FUN_00044ad0(FUN_0027b020(variation));
 if(!item) { void* memory=FUN_0008d690(0x568); item=memory ? ((Template_47770*)memory)->FUN_00045840() : 0; }
 item->retain();
 item->FUN_000464c0(data,node);
 if(count<capacity) { Template_47770** slot=entries+count; item->retain(); if(*slot) (*slot)->release(); *slot=item; ++count; }
 item->release();
}

// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_0031e500 @ 0x0031e500
struct Resource_31e500 { virtual void destroy(unsigned int) throw(); virtual void release() throw(); };
struct Extra_31e500 { void FUN_00328260() throw(); };
void __cdecl FUN_0008d330(void*) throw();
namespace pure3d {
struct pddiRenderContext {
 virtual void slot0();
 char pad04[8]; Resource_31e500* resourceC; Resource_31e500* resource10;
 char pad14[12]; Resource_31e500* objects[10]; char pad48[0xfc]; Extra_31e500* extra;
 void FUN_0031bae0() throw();
 ~pddiRenderContext() throw() { FUN_0031bae0(); }
};
struct pddiBaseContext : pddiRenderContext {
 virtual void slot0();
 ~pddiBaseContext() throw();
};
pddiBaseContext::~pddiBaseContext() throw() {
 resource10->release(); resourceC->release();
 for(int i=0;i<10;++i) if(objects[i]) objects[i]->destroy(1);
 Extra_31e500* p=extra;
 if(p) {p->FUN_00328260(); FUN_0008d330(p);}
}
}

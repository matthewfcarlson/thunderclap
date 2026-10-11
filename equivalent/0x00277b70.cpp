// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_00277b70 @ 0x00277b70
struct Base {
 virtual void slot0();
 virtual void release();
 Base* FUN_002764d0(unsigned int a,unsigned int b,int c,int d,int e,int f,int g,int h,int i);
};
struct Object { Object* FUN_00277a70(unsigned int a,Base* b,unsigned int c); };
extern "C" Base* __cdecl FUN_00275d50(unsigned int size);
extern "C" Object* __cdecl FUN_00266e00(unsigned int a,unsigned int size);
extern unsigned int DAT_004cdbb0;
void __cdecl FUN_00277b70(Object** out,unsigned int a,unsigned int b,unsigned int c,unsigned int d) {
 Base* p=FUN_00275d50(0x168);
 Base* base=0;
 if(p) base=p->FUN_002764d0(a,b,0,0,1,0,0,0,1);
 DAT_004cdbb0=d;
 Object* mem=FUN_00266e00(d,0x74);
 Object* result=0;
 if(mem) result=mem->FUN_00277a70(a,base,c);
 base->release();
 *out=result;
}
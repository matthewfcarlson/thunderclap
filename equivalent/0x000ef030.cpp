// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 12/12)
// FEContainer::vfunc_5 @ 0x000ef030
struct TypeInfo_ef030 { unsigned int data; }; extern TypeInfo_ef030 DAT_0049dba4; extern TypeInfo_ef030 DAT_0049f470;
struct Text_ef030 { char pad[0x2c]; int id; };
extern Text_ef030* __cdecl FUN_00344e74(void*, int, TypeInfo_ef030*, TypeInfo_ef030*, int);
struct Brief { int FUN_000f7d30(); };
struct Page { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual const char* f8(); };
struct Owner_ef030 {
virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39(); virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); virtual Brief* f44(const char*); virtual void f45(); virtual void f46(); virtual void f47(); virtual void f48(int); virtual void f49(const char*);
char pad[0x1758]; Page* page; char pad2[0x98]; int state;
void* FUN_000e7260(const char*);
};
struct FEContainer { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); Owner_ef030* owner; void FUN_000e4ec0(int); };
void FEContainer::vfunc_5() {
 FUN_000e4ec0(6);
 Text_ef030* text=FUN_00344e74(owner->FUN_000e7260("fullscreen_message_text"),0,&DAT_0049dba4,&DAT_0049f470,0);
 bool special=false;
 if(text) {
 int id=text->id;
 int expected=owner->f44("TBS_MISSION_BRIEF_C7M2")->FUN_000f7d30();
 if(id==expected && owner->page) {
 const char* name=owner->page->f8(); const char* wanted="fullscreen_message";
 special=true; for(int i=0;i<19;++i) if(name[i]!=wanted[i]) {special=false;break;}
 }
 }
 if(special) owner->f49("c07m02"); else owner->f48(5);
 if(owner->state==0) FUN_000e4ec0(10);
 if(owner->state==1) FUN_000e4ec0(11);
}

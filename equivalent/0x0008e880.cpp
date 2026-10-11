// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 39/42, incomplete)
// FUN_0008e880 @ 0x0008e880
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) { return p; }
struct Stream;
class CPlatformManager { public: char pad[4]; Stream* archive; void FUN_0008e880(); void FUN_0008dec0(); void FUN_0008da80(const char*); void FUN_0008dac0(const char*); void FUN_0008dad0(const char*); };
struct Ref { virtual void add(); virtual void release(); Ref* FUN_00266480(int); };
extern Ref *DAT_004dd9c8,*DAT_004dd9cc;
void* __cdecl FUN_0008d690(int); void* __cdecl FUN_00263ea0(int);
struct Command { void* FUN_0008e6b0(const char*,CPlatformManager*,void(CPlatformManager::*)(const char*)); void FUN_001d0480(const char*,int); };
struct Registry { void FUN_001d3b70(const char*,void*); };
Registry* FUN_001d4c90();
extern int DAT_0048e100,DAT_0048e0f0,DAT_0049ca0c;
unsigned char FUN_001d04d0(void*);
template<class T,class R,class A> class Method1 { public: virtual void v0(); char pad[12]; unsigned char a; char pad2[7]; unsigned char b; char pad3[3]; void(T::*method)(A); };
template<class T,class R,class A> class Closure1 : public Method1<T,R,A> { public: virtual void v0(); T* owner; };
struct MyControllerCallback { virtual void v0(); unsigned char flags[6]; };
extern MyControllerCallback* DAT_004dd7e0;
extern unsigned char DAT_004dd83f,DAT_004dd8e4;
extern unsigned int DAT_004d9968; void __fastcall __security_check_cookie(unsigned int);
void FUN_0022e340(); void FUN_00269640(MyControllerCallback*,int,int); void FUN_00333b50(int); void FUN_000966f0();
struct Stream { virtual void s0(); virtual void release(); virtual void s2(); virtual void read(char*,int,int); virtual void activate(); virtual void s5(); virtual void s6(); virtual void length(int*); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void sync(); virtual void s22(); virtual unsigned char valid(); virtual void configure(void*,int); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void enable(int); };
void thunk_FUN_00270b70(void*); void thunk_FUN_00271530(Stream**,void*,int,int); void thunk_FUN_002710d0(Stream**,const char*,int,int,int,int,int,int); void thunk_FUN_00271560(Stream**,const char*,int,int);
void CPlatformManager::FUN_0008e880() {
struct Frame {Stream* file;Stream* s;int n;CPlatformManager* owner;char* tokens[64];char config[16];char text[2048];int unused;unsigned int cookie;} f;
f.owner=this;f.cookie=DAT_004d9968;
Ref* r=0; Ref* mem=(Ref*)FUN_00263ea0(20); if(mem) { r=mem->FUN_00266480(128); if(r)r->add(); } if(DAT_004dd9c8)DAT_004dd9c8->release(); DAT_004dd9c8=r;
r=0; mem=(Ref*)FUN_00263ea0(20); if(mem) {r=mem->FUN_00266480(1024);if(r)r->add();}if(DAT_004dd9cc)DAT_004dd9cc->release();DAT_004dd9cc=r;
Registry* reg=FUN_001d4c90(); if(reg) { Command* c=(Command*)FUN_0008d690(36);void* cmd=0;if(c)cmd=c->FUN_0008e6b0("debug_SetChanel",this,&CPlatformManager::FUN_0008da80);reg->FUN_001d3b70("debug_SetChanel",cmd);
for(int j=0;j<2;++j){const char* name=j?"debug_DisableChannel":"debug_EnableChannel";void* p=FUN_0008d690(36);if(p){((Command*)p)->FUN_001d0480(name,1);Method1<CPlatformManager,void,const char*>* m=new(p) Method1<CPlatformManager,void,const char*>;m->method=j?&CPlatformManager::FUN_0008dad0:&CPlatformManager::FUN_0008dac0;m->b=FUN_001d04d0(&DAT_0048e100);m->a=FUN_001d04d0(&DAT_0048e0f0);Closure1<CPlatformManager,void,const char*>* cl=new(p) Closure1<CPlatformManager,void,const char*>;cl->owner=this;}reg->FUN_001d3b70(name,p);}}
FUN_0022e340();FUN_0008dec0();thunk_FUN_00270b70(f.config);thunk_FUN_00271530(&f.s,f.config,1,0);f.s->configure(&DAT_0049ca0c,0);f.s->enable(1);f.s->release();
MyControllerCallback* cb=DAT_004dd7e0;if(!cb){void* p=FUN_0008d690(12);cb=0;if(p){cb=new(p) MyControllerCallback;for(int k=0;k<6;++k)cb->flags[k]=0;}DAT_004dd7e0=cb;}FUN_00269640(cb,0,0);FUN_00333b50(0);
if(!DAT_004dd83f){f.file=0;thunk_FUN_002710d0(&f.file,"rcfs.txt",0,0,1,0,1,1);f.file->sync();if(f.file->valid()){f.file->length(&f.n);f.file->sync();f.file->read(f.text,f.n,1);f.file->sync();f.text[f.n]=0;for(int k=0;k<64;++k)f.tokens[k]=0;f.tokens[0]=f.text;int count=1;char* p=f.text;if(*p){do{if(*p==','){f.tokens[count]=p+1;*p=0;++count;}++p;}while(*p);}Stream** out=&f.owner->archive;for(int i=0;i<count;++i){thunk_FUN_00271560(out,f.tokens[i],0,18);if(*out)(*out)->activate();}}f.file->release();}if(DAT_004dd8e4)FUN_000966f0();__security_check_cookie(f.cookie);
}
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00277a70 @ 0x00277a70
typedef unsigned int uint;
extern uint DAT_004cdbb0;
void FUN_002705f0();
namespace core {
struct ICementLibrary { virtual void slot0(); };
struct IFileCompletionCallback { virtual void slot0(); };
struct Object { virtual void slot0(); uint tag; };
struct SafeRefCount { virtual void slot0(); uint refs; };
struct Resource { virtual void slot0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(IFileCompletionCallback*,uint); };
struct CementLibrary : ICementLibrary, IFileCompletionCallback, Object, SafeRefCount {
virtual void slot0();
Resource *a,*b; uint zero20; char pad[60]; uint x60,x64,x68,x6c,x70;
CementLibrary* FUN_00277a70(Resource*,Resource*,uint);
};
CementLibrary* CementLibrary::FUN_00277a70(Resource* aa,Resource* bb,uint n) { this->ICementLibrary::ICementLibrary(); this->IFileCompletionCallback::IFileCompletionCallback(); this->Object::Object(); tag=DAT_004cdbb0; FUN_002705f0(); this->SafeRefCount::SafeRefCount(); refs=1; this->CementLibrary::CementLibrary(); a=aa;b=bb;zero20=0;x60=0;x64=0;x68=n;x6c=0;x70=0;FUN_002705f0();a->slot0();b->slot0();b->s18(this,0); return this; }
}

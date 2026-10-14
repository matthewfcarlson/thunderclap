// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_00072360 @ 0x00072360
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_00068960();
void __cdecl FUN_00068970();
void __cdecl FUN_00068980();
class CInvulnerableTrack;
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 void FUN_00234960(const char*);
 char pad[12];
 void (__cdecl *callback)();
 int tail;
};
}
extern int DAT_004dcfdc;
extern int DAT_004dcfd8;
typedef fight::ParamFloatConstRange<CInvulnerableTrack> Param;
void __cdecl FUN_002347b0(void*, Param**, int);
void __cdecl FUN_00072360() {
 if (!DAT_004dcfdc) {
 Param* entries[3];
 const char* names[3]={"timeBegin","timeEnd","extensionTime"};
 void (__cdecl *callbacks[3])()={FUN_00068960,FUN_00068970,FUN_00068980};
 for(int i=0;i<3;++i) {
 Param* p=(Param*)FUN_0008d690(24);
 if(p) {
 p->FUN_00234960(names[i]);
 p->fight::ParamFloatConstRange<CInvulnerableTrack>::ParamFloatConstRange();
 p->callback=callbacks[i];
 }
 entries[i]=p;
 }
 FUN_002347b0(&DAT_004dcfd8,entries,3);
 }
 ++DAT_004dcfdc;
}
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_000b51c0 @ 0x000b51c0
extern const char *DAT_0049f3b8;
extern unsigned int DAT_004d9968;
// equiv-conv: __security_check_cookie ecx
extern void __cdecl __security_check_cookie(unsigned int);
extern const char *__cdecl FUN_000f7120(int);
extern int __cdecl FUN_000964a0(char *, int, const char *, ...);
struct Resource {
 virtual void slot0(); virtual void release();
 virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13();
 virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17();
 virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21();
 virtual void slot22(); virtual unsigned char ready();
};
extern void __cdecl thunk_FUN_00271230(Resource **, const char *, int, int, int, int, int, int);
bool __cdecl FUN_000b51c0(int language) {
 unsigned int cookie=DAT_004d9968;
 int index=0;
 for (; index<6; ++index) { if (index==language) break; }
 if(index==6) index=0;
 char filename[64];
 FUN_000964a0(filename,64,DAT_0049f3b8,FUN_000f7120(index));
 Resource *resource;
 thunk_FUN_00271230(&resource,filename,0,0,1,0,1,1);
 bool result=resource->ready()!=0;
 resource->release();
 __security_check_cookie(cookie);
 return result;
}
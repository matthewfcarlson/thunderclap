// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_0008fca0 @ 0x0008fca0
// FUN_0008fca0 @ 0x0008fca0
struct File { virtual void slot0(); virtual void release(); virtual void slot2(); virtual void read(char*,int,int); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void size(int*); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void sync(); virtual void slot22(); virtual bool ready(); };
extern void __cdecl thunk_FUN_002710d0(File**,const char*,int,int,int,int,int,int);
extern int __cdecl _isspace(int);
extern void __cdecl FUN_0008f880(int,char**);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
void __cdecl FUN_0008fca0() {
 struct Frame { File* file; int length; char* args[256]; char buffer[2048]; int pad; unsigned int cookie; } f;
 f.cookie=DAT_004d9968; f.file=0;
 thunk_FUN_002710d0(&f.file,"args.txt",0,0,1,0,1,1); f.file->sync();
 if(f.file->ready()) {
 f.file->size(&f.length); f.file->sync(); f.file->read(f.buffer,f.length,1); f.file->sync();
 f.buffer[f.length]=0;
 for(int i=0;i<64;++i) f.args[i]=0;
 char* p=f.buffer; f.args[1]=p; int count=2;
 while(*p) { int c=(signed char)*p++; if(_isspace(c) && !_isspace((signed char)*p)) f.args[count++]=p;
 if(p[-1]==' ' || p[-1]=='\n' || p[-1]=='\r') p[-1]=0; }
 if(*f.args[count-1]==0) --count;
 FUN_0008f880(count,f.args);
 }
 f.file->release(); __security_check_cookie(f.cookie);
}

// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 15/18, incomplete)
// FUN_0008fca0 @ 0x0008fca0
struct File { virtual void slot0(); virtual void release(); virtual void slot2(); virtual void read(char*,int,int); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void size(int*); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void sync(); virtual void slot22(); virtual bool ready(); };
extern void __cdecl thunk_FUN_002710d0(File**,const char*,int,int,int,int,int,int);
extern int __cdecl _isspace(int);
extern void __cdecl FUN_0008f880(int,char**);
extern unsigned int DAT_004d9968;
// equiv-conv: __security_check_cookie ecx
extern void __cdecl __security_check_cookie(unsigned int);
void __cdecl FUN_0008fca0() {
 unsigned int cookie=DAT_004d9968; File* file=0;
 thunk_FUN_002710d0(&file,"args.txt",0,0,1,0,1,1); file->sync();
 if(file->ready()) {
 int length;
 union Scratch { double alignment; struct { char* args[256]; char buffer[2048]; char padding[8]; } data; } scratch;
 file->size(&length); file->sync(); file->read(scratch.data.buffer,length,1); file->sync();
 scratch.data.buffer[length]=0;
 for(int i=0;i<64;++i) scratch.data.args[i]=0;
 char* p=scratch.data.buffer; scratch.data.args[1]=p; int count=2;
 while(*p) { int c=(signed char)*p++; if(_isspace(c) && !_isspace((signed char)*p)) scratch.data.args[count++]=p;
 if(p[-1]==' ' || p[-1]=='\n' || p[-1]=='\r') p[-1]=0; }
 if(*scratch.data.args[count-1]==0) --count;
 FUN_0008f880(count,scratch.data.args);
 }
 file->release(); __security_check_cookie(cookie);
}
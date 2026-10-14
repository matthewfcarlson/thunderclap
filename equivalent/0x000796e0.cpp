// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000796e0 @ 0x000796e0
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct Matrix { char data[64]; void FUN_0022b980(); void FUN_0022cc90(const void*); void FUN_0022be40(const void*); };
struct Request { char data[8]; Request* FUN_0027b0e0(const char*, unsigned int, Matrix*, unsigned int, unsigned int, unsigned int, unsigned int); void FUN_0027af50(); };
struct Manager { unsigned int FUN_001dd330(Request*); };
struct Holder { char pad[12]; Manager* manager; };
extern "C" int __cdecl FUN_000964a0(char*, unsigned int, const char*, ...);
struct Object { char pad[0x382c]; Holder* holder; unsigned int FUN_000796e0(unsigned int, const char*, const void*, const void*, unsigned int, unsigned int, unsigned int); };
unsigned int Object::FUN_000796e0(unsigned int a, const char* name, const void* p, const void* q, unsigned int b, unsigned int c, unsigned int d) { unsigned int cookie=DAT_004d9968; Matrix m; m.FUN_0022b980(); m.FUN_0022cc90(q); m.FUN_0022be40(p); char text[64]; FUN_000964a0(text,64,"%s_prop",name); Manager* manager=holder->manager; Request r; Request* request=r.FUN_0027b0e0(text,a,&m,b,c,d,0); unsigned int result=manager->FUN_001dd330(request); r.FUN_0027af50(); __security_check_cookie(cookie); return result; }
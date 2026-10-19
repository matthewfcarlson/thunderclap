// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// FUN_000796e0 @ 0x000796e0
// cl-flags: /GS
struct Matrix { char data[64]; void FUN_0022b980(); void FUN_0022cc90(const void*); void FUN_0022be40(const void*); };
struct Request { char data[8]; Request* FUN_0027b0e0(const char*, unsigned int, Matrix*, unsigned int, unsigned int, unsigned int, unsigned int); void FUN_0027af50(); };
struct Manager_796e0 { unsigned int FUN_001dd330(Request*); };
struct Holder_796e0 { char pad[12]; Manager_796e0* manager; };
extern "C" int __cdecl FUN_000964a0(char*, unsigned int, const char*, ...);
struct Object { char pad[0x382c]; Holder_796e0* holder; unsigned int FUN_000796e0(unsigned int, const char*, const void*, const void*, unsigned int, unsigned int, unsigned int); };
unsigned int Object::FUN_000796e0(unsigned int a, const char* name, const void* p, const void* q, unsigned int b, unsigned int c, unsigned int d) { Matrix m; m.FUN_0022b980(); m.FUN_0022cc90(q); m.FUN_0022be40(p); char text[64]; FUN_000964a0(text,64,"%s_prop",name); Manager_796e0* manager=holder->manager; Request r; Request* request=r.FUN_0027b0e0(text,a,&m,b,c,d,0); unsigned int result=manager->FUN_001dd330(request); r.FUN_0027af50();  return result; }
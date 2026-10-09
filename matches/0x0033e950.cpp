extern int __cdecl F00212d30(void*);
extern int __cdecl F00212f00(void*, int);
extern int __cdecl F00212f40(void*, int);
extern void __cdecl F00339c30(void*, int, const char*);
extern void __cdecl F00212ed0(void*, int);
extern void __cdecl F00212cb0(void*, int, int);
extern const char luaerr[];
int __cdecl target(void* p) {
 int saved=F00212d30(p);
 int t=F00212f00(p,1);
 if (t != 6 || F00212f40(p,1) != 0) F00339c30(p,1,luaerr);
 F00212ed0(p,1);
 F00212cb0(p,saved,1);
 return 1;
}
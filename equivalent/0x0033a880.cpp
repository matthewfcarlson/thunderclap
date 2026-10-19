// STATUS: equivalent (tools/equiv.py level 3: 10073 inputs, branch coverage 12/12)
// FUN_0033a880 @ 0x0033a880
// FUN_0033a880 @ 0x0033a880
struct State;
typedef void (__cdecl *Hook_33a880)();
extern unsigned int DAT_004d9968;
extern "C" {
int __cdecl FUN_00212f00(State*, int);
State* __cdecl FUN_00213290(State*, int);
int __cdecl FUN_00213fa0(State*);
Hook_33a880 __cdecl FUN_00213f90(State*);
void __cdecl FUN_0033a620();
void __cdecl FUN_00213380(State*, const char*, int);
// equiv-conv: FUN_0033a740 esi
void __cdecl FUN_0033a740(State*);
void __cdecl FUN_00213550(State*, State*);
void __cdecl FUN_00213600(State*, int);
void __cdecl FUN_00212de0(State*, int);
void __cdecl FUN_00212cb0(State*, State*, int);
void __cdecl FUN_002133d0(State*, const char*);
int __cdecl FUN_00213fb0(State*);
void __cdecl FUN_00213360(State*, int);
void __fastcall __security_check_cookie(unsigned int);
}
int __cdecl FUN_0033a880(State* state) {
unsigned int cookie=DAT_004d9968;
State* source = state;
if (FUN_00212f00(state,1)==8) source=FUN_00213290(state,1);
int flags=FUN_00213fa0(source);
Hook_33a880 hook=FUN_00213f90(source);
if(hook && hook != (Hook_33a880)FUN_0033a620) {
FUN_00213380(state,"external hook",13);
} else {
FUN_0033a740(source);
FUN_00213550(source,source);
FUN_00213600(source,-2);
FUN_00212de0(source,-2);
FUN_00212cb0(source,state,1);
}
char mode[4]; int count=0;
if(flags&1) mode[count++]='c';
if(flags&2) mode[count++]='r';
if(flags&4) mode[count++]='l';
mode[count]=0;
FUN_002133d0(state,mode);
int value=FUN_00213fb0(source);
FUN_00213360(state,value);
__security_check_cookie(cookie);
return 3;
}

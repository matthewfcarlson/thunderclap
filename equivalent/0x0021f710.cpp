// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 6/6)
// FUN_0021f710 @ 0x0021f710
struct State { unsigned int a, value, savedValue, result, savedToken, token, tokenData; char pad[12]; unsigned int option; unsigned int pad2; unsigned int zero; char buffer[520]; };
extern unsigned int DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned int);
extern int __cdecl FUN_00219430(void*, const char*, unsigned int);
extern void __cdecl FUN_0021b160(void*, State*, unsigned int, int);
// equiv-conv: FUN_0021cac0 ecx eax
extern void FUN_0021cac0(State*, char*);
extern unsigned int __cdecl FUN_0021bbc0(State*, unsigned int*);
extern void __cdecl FUN_0021f640(State*);
extern void __cdecl FUN_0021b060(State*, const char*);
extern void __cdecl FUN_0021cb80(State*);
unsigned int __cdecl FUN_0021f710(void* context, unsigned int arg2, unsigned int option, const char* text) {
 unsigned int cookie = DAT_004d9968;
 State s;
 s.option = option;
 s.zero = 0;
 unsigned int length = 0;
 while(text[length]) ++length;
 int v = FUN_00219430(context, text, length);
 FUN_0021b160(context, &s, arg2, v);
 FUN_0021cac0(&s, s.buffer);
 s.savedValue = s.value;
 unsigned int token = s.token;
 if(token != 0x11f) { s.savedToken = s.tokenData; s.token = 0x11f; }
 else token = FUN_0021bbc0(&s, &s.savedToken);
 s.result = token;
 FUN_0021f640(&s);
 if(s.result != 0x11f) FUN_0021b060(&s, "<eof> expected");
 FUN_0021cb80(&s);
 unsigned int result = *(unsigned int*)s.buffer;
 __security_check_cookie(cookie);
 return result;
}

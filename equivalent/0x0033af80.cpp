// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 10/10)
// FUN_0033af80 @ 0x0033af80
// cl-flags: /GS
extern "C" {
int __cdecl FUN_00339e60(void*, int, const char*, int*);
int __cdecl FUN_00339fe0(void*, int, int);
void __cdecl FUN_00339d70(void*, int, int);
int __cdecl FUN_003392c0(void*, int);
void __cdecl FUN_00339630(void*, void*);
void __cdecl FUN_00213640(void*, int, int);
int __cdecl FUN_00212fb0(void*, int);
void __cdecl FUN_00339c30(void*, int, const char*);
void __cdecl FUN_00339590(void*);
void __cdecl FUN_003394b0(void*, int, int);
void __cdecl FUN_00339540(void*);
}
int __cdecl FUN_0033af80(void* state) {
 int separatorLength;
 char buffer[0x20c];
 int separator=FUN_00339e60(state,2,"",&separatorLength);
 int first=FUN_00339fe0(state,3,1);
 int last=FUN_00339fe0(state,4,0);
 FUN_00339d70(state,1,5);
 if (!last) last=FUN_003392c0(state,1);
 FUN_00339630(state,buffer);
 for(int i=first;i<=last;++i) {
  FUN_00213640(state,1,i);
  if(!FUN_00212fb0(state,-1)) FUN_00339c30(state,1,"table contains non-strings");
  FUN_00339590(buffer);
  if(i!=last) FUN_003394b0(buffer,separator,separatorLength);
 }
 FUN_00339540(buffer);
 return 1;
}

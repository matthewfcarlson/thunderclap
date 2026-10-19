// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 6/6)
// FUN_0033a340 @ 0x0033a340
// cl-flags: /GS
struct State;
extern "C" int __cdecl FUN_00212f00(State*, int);
extern "C" State* __cdecl FUN_00213290(State*, int);
extern "C" int __cdecl FUN_00339f70(State*, int);
extern "C" int __cdecl FUN_00213fc0(State*, int, void*);
extern "C" int __cdecl FUN_00339c30(State*, int, const char*);
extern "C" int __cdecl FUN_00214050(State*, void*, int);
extern "C" void __cdecl FUN_00212cb0(State*, State*, int);
extern "C" void __cdecl FUN_002133d0(State*, int);
extern "C" void __cdecl FUN_00212ed0(State*, int);
extern "C" void __cdecl FUN_00213320(State*);
int __cdecl target(State* state) {
 char buffer[96];
 State* other = state;
 int base = 0;
 if (FUN_00212f00(state,1)==8) { base=1; other=FUN_00213290(state,1); }
 int level=FUN_00339f70(state,base+1);
 int ok=FUN_00213fc0(other,level,buffer);
 int ret;
 if (!ok) ret=FUN_00339c30(state,base+1,"level out of range");
 else {
 int item=FUN_00339f70(state,base+2);
 int result=FUN_00214050(other,buffer,item);
 if(result) {
 FUN_00212cb0(other,state,1);
 FUN_002133d0(state,result);
 FUN_00212ed0(state,-2);
 ret=2;
 } else {
 FUN_00213320(state);
 ret=1;
 }
 }
 return ret;
}
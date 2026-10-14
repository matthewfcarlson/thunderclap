// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 22/22)
// FUN_0033cff0 @ 0x0033cff0
struct State;
struct Capture_33cff0 { const char* start; int length; };
struct MatchState_33cff0 { const char* start; const char* end; State* state; int level; Capture_33cff0 captures[32]; };
struct Buffer_33cff0 { char* cursor; int level; State* state; char data[512]; };
extern unsigned DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned);
extern const char* __cdecl FUN_00339df0(State*,int,unsigned*);
extern int __cdecl FUN_00339fe0(State*,int,unsigned);
extern int __cdecl FUN_00212d70(State*);
extern int __cdecl FUN_00212fb0(State*,int);
extern int __cdecl FUN_00212f00(State*,int);
extern void __cdecl FUN_00339c30(State*,int,const char*);
extern void __cdecl FUN_00339630(State*,Buffer_33cff0*);
extern const char* __cdecl FUN_0033c7e0(MatchState_33cff0*,const char*,const char*);
// equiv-conv: FUN_0033cec0 eax ebx stack stack
extern void __cdecl FUN_0033cec0(MatchState_33cff0*,Buffer_33cff0*,const char*,const char*);
extern void __cdecl FUN_00339470(Buffer_33cff0*);
extern void __cdecl FUN_003394b0(Buffer_33cff0*,const char*,unsigned);
extern void __cdecl FUN_00339540(Buffer_33cff0*);
extern void __cdecl FUN_00213360(State*,int);
int __cdecl FUN_0033cff0(State* state) {
 unsigned cookie=DAT_004d9968;
 unsigned length;
 const char* source=FUN_00339df0(state,1,&length);
 const char* pattern=FUN_00339df0(state,2,0);
 int maximum=FUN_00339fe0(state,4,length+1);
 bool anchored=(*pattern=='^');
 if(anchored) ++pattern;
 int count=0;
 if(FUN_00212d70(state)<3 || (!FUN_00212fb0(state,3) && FUN_00212f00(state,3)!=6))
 FUN_00339c30(state,3,"string or function expected");
 Buffer_33cff0 buffer;
 FUN_00339630(state,&buffer);
 MatchState_33cff0 match;
 match.state=state; match.start=source; match.end=source+length;
 if(maximum>0) {
 do {
 match.level=0;
 const char* result=FUN_0033c7e0(&match,source,pattern);
 if(result) { ++count; FUN_0033cec0(&match,&buffer,source,result); }
 if(result && result>source) source=result;
 else {
 if(source>=match.end) break;
 if(buffer.cursor>=buffer.data+512) FUN_00339470(&buffer);
 *buffer.cursor=*source;
 ++buffer.cursor; ++source;
 }
 } while(!anchored && count<maximum);
 }
 FUN_003394b0(&buffer,source,(unsigned)(match.end-source));
 FUN_00339540(&buffer);
 FUN_00213360(state,count);
 __security_check_cookie(cookie);
 return 2;
}
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0033a7a0 @ 0x0033a7a0
typedef unsigned int U;
extern "C" int __cdecl FUN_00212f00(U,int);
extern "C" U __cdecl FUN_00213290(U,int);
extern "C" void __cdecl FUN_00212d80(U,int);
extern "C" int __cdecl FUN_0033a620(U);
extern "C" void __cdecl FUN_00213f60(U,int (__cdecl *)(U),U,U);
extern "C" U __cdecl FUN_00339df0(U,int,int);
extern "C" U __cdecl FUN_00339fe0(U,int,int);
extern "C" U __cdecl FUN_00339d70(U,int,int);
// equiv-conv: FUN_0033a6b0 edi stack
extern "C" U __cdecl FUN_0033a6b0(U,U);
extern "C" void __cdecl FUN_0033a740();
extern "C" void __cdecl FUN_00213550(U,U);
extern "C" void __cdecl FUN_00212ed0(U,int);
extern "C" void __cdecl FUN_00212cb0(U,U,int);
extern "C" void __cdecl FUN_00213800(U,int);
extern "C" int __cdecl FUN_0033a7a0(U state) {
 int offset=0; U context=state;
 if(FUN_00212f00(state,1)==8){offset=1; context=FUN_00213290(state,1);}
 int index=offset+1;
 if(FUN_00212f00(state,index)<=0){FUN_00212d80(state,index); FUN_00213f60(context,0,0,0);}
 else {U first=FUN_00339df0(state,offset+2,0); U second=FUN_00339fe0(state,offset+3,0); FUN_00339d70(state,index,6); U result=FUN_0033a6b0(first,second); FUN_00213f60(context,FUN_0033a620,result,second);}
 FUN_0033a740(); FUN_00213550(context,context); FUN_00212ed0(state,index); FUN_00212cb0(state,context,1); FUN_00213800(context,-3); FUN_00212d80(context,-2); return 0;
}
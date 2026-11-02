// STATUS: equivalent (tools/equiv.py level 3: 20026 inputs, branch coverage 10/10)
// FUN_0021db50 @ 0x0021db50
// FUN_0021db50 @ 0x0021db50
struct Input_21db50 { char pad0[4]; unsigned int value; char pad8[4]; unsigned int kind; unsigned int data; char pad14[8]; unsigned int context; };
struct Output_21db50 { unsigned int type; unsigned int value; unsigned int reserved; int a; int b; };
extern unsigned int __cdecl FUN_002209e0(unsigned int, unsigned int);
// equiv-conv: FUN_0021c190 esi
extern "C" void __cdecl FUN_0021c190(void *);
// equiv-conv: FUN_0021c440 ecx eax esi
extern "C" void __cdecl FUN_0021c440(void *, int, void *);
// equiv-conv: FUN_0021cf70 ecx eax
extern "C" void __cdecl FUN_0021cf70(void *, void *);
// equiv-conv: FUN_0021d4b0 ebx stack stack stack
extern void __cdecl FUN_0021d4b0(Input_21db50*, Output_21db50*, int, unsigned int);
// equiv-conv: FUN_0021d830 eax esi
extern "C" void __cdecl FUN_0021d830(void *, void *);
// equiv-conv: FUN_0021db50 eax edi
extern "C" void FUN_0021db50(void * input, void * output) {
 unsigned int k=((Input_21db50 *)input)->kind-0x7b;
 unsigned int branch=k==0 ? 0 : k==140 ? 1 : k==142 ? 2 : k==146 ? 3 : k==152 ? 4 : k==162 ? 5 : k==163 ? 6 : 7;
 switch(branch) {
 case 5: { unsigned int v=FUN_002209e0(((Input_21db50 *)input)->context,((Input_21db50 *)input)->data); ((Output_21db50 *)output)->a=-1;((Output_21db50 *)output)->b=-1;((Output_21db50 *)output)->type=4;((Output_21db50 *)output)->value=v;FUN_0021c190((Input_21db50 *)((Input_21db50 *)input));break; }
 case 6: FUN_0021c440((Input_21db50 *)((Input_21db50 *)input),(unsigned int)(((Input_21db50 *)input)->data),(Output_21db50 *)((Output_21db50 *)output));FUN_0021c190((Input_21db50 *)((Input_21db50 *)input));break;
 case 3: case 4: case 1: ((Output_21db50 *)output)->a=-1;((Output_21db50 *)output)->b=-1;((Output_21db50 *)output)->type=branch==1?3:branch==3?1:2;((Output_21db50 *)output)->value=0;FUN_0021c190((Input_21db50 *)((Input_21db50 *)input));break;
 case 0: FUN_0021cf70((Input_21db50 *)((Input_21db50 *)input),(Output_21db50 *)((Output_21db50 *)output));break;
 case 2: FUN_0021c190((Input_21db50 *)((Input_21db50 *)input));FUN_0021d4b0(((Input_21db50 *)input),((Output_21db50 *)output),0,((Input_21db50 *)input)->value);break;
 default: FUN_0021d830((Output_21db50 *)((Output_21db50 *)output),(Input_21db50 *)((Input_21db50 *)input));break;
 }
}

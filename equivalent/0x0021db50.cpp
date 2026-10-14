// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 10/10)
// FUN_0021db50 @ 0x0021db50
struct Input_21db50 { char pad0[4]; unsigned int value; char pad8[4]; unsigned int kind; unsigned int data; char pad14[8]; unsigned int context; };
struct Output_21db50 { unsigned int type; unsigned int value; unsigned int reserved; int a; int b; };
extern unsigned char DAT_0021dc68[164];
extern unsigned int __cdecl FUN_002209e0(unsigned int, unsigned int);
// equiv-conv: FUN_0021c190 esi
extern void FUN_0021c190(Input_21db50*);
// equiv-conv: FUN_0021c440 ecx eax esi
extern void FUN_0021c440(Input_21db50*, unsigned int, Output_21db50*);
// equiv-conv: FUN_0021cf70 ecx eax
extern void FUN_0021cf70(Input_21db50*, Output_21db50*);
extern void __cdecl FUN_0021d4b0(Output_21db50*, int, unsigned int);
// equiv-conv: FUN_0021d830 eax esi
extern void FUN_0021d830(Output_21db50*, Input_21db50*);
// equiv-conv: FUN_0021db50 eax edi
void FUN_0021db50(Input_21db50* input, Output_21db50* output) {
 unsigned int k=input->kind-0x7b;
 unsigned int branch=k<=0xa3 ? DAT_0021dc68[k] : 7;
 switch(branch) {
 case 5: { unsigned int v=FUN_002209e0(input->context,input->data); output->a=-1;output->b=-1;output->type=4;output->value=v;FUN_0021c190(input);break; }
 case 6: FUN_0021c440(input,input->data,output);FUN_0021c190(input);break;
 case 3: case 4: case 1: output->a=-1;output->b=-1;output->type=branch==1?3:branch==3?1:2;output->value=0;FUN_0021c190(input);break;
 case 0: FUN_0021cf70(input,output);break;
 case 2: FUN_0021c190(input);FUN_0021d4b0(output,0,input->value);break;
 default: FUN_0021d830(output,input);break;
 }
}
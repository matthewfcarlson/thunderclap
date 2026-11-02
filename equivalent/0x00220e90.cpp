// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 12/12)
// FUN_00220e90 @ 0x00220e90
struct State_220e90 { unsigned kind; unsigned value; };
struct Buffer_220e90 { char pad[12]; unsigned* words; };
struct Context { Buffer_220e90* buffer; };
void __cdecl FUN_00220d90(Context*, State_220e90*);
void __cdecl FUN_00220c40(Context*, unsigned, int);
extern "C" int __cdecl FUN_00220bd0(void *, unsigned int, int, unsigned int, unsigned int);
extern "C" int __cdecl FUN_00220c10(void *, unsigned int, int, unsigned int);
// equiv-conv: FUN_00220e90 ebx esi edi
extern "C" void FUN_00220e90(void * state, unsigned value, void * context) {
 FUN_00220d90(((Context *)context), ((State_220e90 *)state));
 switch(((State_220e90 *)state)->kind) {
 case 1: FUN_00220c40(((Context *)context),value,1); break;
 case 2: case 3: FUN_00220bd0((Context *)((Context *)context),2,(unsigned)value,(unsigned)(((State_220e90 *)state)->kind==2),0); break;
 case 4: FUN_00220c10((Context *)((Context *)context),1,(unsigned)value,(unsigned)(((State_220e90 *)state)->value)); break;
 case 10: { unsigned& word=((Context *)context)->buffer->words[((State_220e90 *)state)->value]; word=(word&0x00ffffffu)|(value<<24); break; }
 case 11: if(value!=((State_220e90 *)state)->value) FUN_00220bd0((Context *)((Context *)context),0,(unsigned)value,(unsigned)(((State_220e90 *)state)->value),0); break;
 default: return;
 }
 ((State_220e90 *)state)->value=value;
 ((State_220e90 *)state)->kind=11;
}

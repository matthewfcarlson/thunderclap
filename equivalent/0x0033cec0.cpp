// STATUS: equivalent (tools/equiv.py level 3: 1899 inputs, branch coverage 22/22)
// FUN_0033cec0 @ 0x0033cec0
// FUN_0033cec0 @ 0x0033cec0
struct Capture_33cec0 { int value; int index; };
struct Context { char pad[8]; void* state; int count; Capture_33cec0 captures[1]; };
struct Buffer_33cec0 { char* cursor; char storage[0x208]; };
extern int __cdecl FUN_00212fb0(void*, int);
extern unsigned char* __cdecl FUN_00213190(void*, int);
extern unsigned int __cdecl FUN_002131f0(void*, int);
extern void __cdecl FUN_00339470(Buffer_33cec0*);
extern int __cdecl _isdigit(int);
extern int __cdecl FUN_00338e20(void*, const char*);
// equiv-conv: FUN_0033cb10 eax esi
extern void* FUN_0033cb10(int, Context*);
extern void FUN_00339590(Buffer_33cec0*);
extern void __cdecl FUN_00212ed0(void*, int);
// equiv-conv: FUN_0033cb70 esi ecx eax
extern void* FUN_0033cb70(Context*, int, int);
extern void __cdecl FUN_002139a0(void*, void*, int);
extern void __cdecl FUN_00212d80(void*, int);
// equiv-conv: FUN_0033cec0 eax ebx stack stack
void target(Context* context, Buffer_33cec0* buffer, int a, int b) {
 void* state = context->state;
 if (FUN_00212fb0(state,3)) {
  unsigned char* text=FUN_00213190(state,3);
  unsigned int length=FUN_002131f0(state,3);
  for(unsigned int i=0;i<length;++i) {
   if(text[i]!='%') {
    if(buffer->cursor >= buffer->storage+sizeof(buffer->storage)) FUN_00339470(buffer);
    *buffer->cursor=text[i]; ++buffer->cursor;
   } else {
    ++i;
    if(!_isdigit(text[i])) {
     if(buffer->cursor >= buffer->storage+sizeof(buffer->storage)) FUN_00339470(buffer);
     *buffer->cursor=text[i]; ++buffer->cursor;
    } else {
     int index=(signed char)text[i]-'1';
     if(index<0 || index>=context->count || context->captures[index].index==-1) index=FUN_00338e20(context->state,"invalid capture index");
     void* value=FUN_0033cb10(index,context);
     FUN_00339590(buffer); (void)value;
    }
   }
  }
 } else {
  FUN_00212ed0(state,3);
  void* v=FUN_0033cb70(context,a,b);
  FUN_002139a0(state,v,1);
  int result=FUN_00212fb0(state,-1);
  if(result) FUN_00339590(buffer);
  else FUN_00212d80(state,-2);
 }
}

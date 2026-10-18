// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 18/18)
// FUN_0021fd10 @ 0x0021fd10
// FUN_0021fd10 @ 0x0021fd10
struct Reader { void* context; void* input; void* allocator; };
struct Output_21fd10 { char pad[0x1c]; void** values; char pad2[4]; int count; char pad3[0x1c]; unsigned char expected; };
// equiv-conv: FUN_0021f8c0 ecx eax edx
void FUN_0021f8c0(int* result, int bytes, Reader* reader);
void __cdecl FUN_0021f800(const char*, ...);
void* __cdecl FUN_0021add0(void*, int, int, unsigned int);
void* __cdecl FUN_0021a6b0(void*, void*, int);
int __cdecl FUN_0021a610(void*, void*, int);
void* __cdecl FUN_00219430(void*, void*, int);
// equiv-conv: FUN_0021fd10 eax stack
void __cdecl FUN_0021fd10(Reader* reader, Output_21fd10* output) {
 struct { int count; int length; } local;
 FUN_0021f8c0(&local.count, 4, reader);
 int count=local.count;
 if(count < 0) { FUN_0021f800("bad integer"); count=local.count; }
 if(count != 0 && count != output->expected) FUN_0021f800("bad nupvalues (read %d; expected %d)", count, (int)output->expected);
 output->values = (void**)FUN_0021add0(reader->context, 0, 0, (unsigned int)count * 4);
 output->count = count;
 for(int i=0;i<count;++i) output->values[i]=0;
 local.count=0;
 for(int i=0;i<count;++i) {
  FUN_0021f8c0(&local.length, 4, reader);
  int length=local.length;
  void* value=0;
  if(length != 0) {
   void* buffer=FUN_0021a6b0(reader->context,reader->allocator,length);
   if(FUN_0021a610(reader->input,buffer,length)) FUN_0021f800("unexpected end of file");
   value=FUN_00219430(reader->context,buffer,length-1);
   i=local.count;
  }
  output->values[i]=value;
  local.count=i+1;
 }
}

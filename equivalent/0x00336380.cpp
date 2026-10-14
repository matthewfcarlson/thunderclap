// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 8/8)
// FUN_00336380 @ 0x00336380
struct Parser { const char* FUN_00337980(); void FUN_003379b0(); };
struct Context { char pad[12]; int* type; };
struct Allocator { void* FUN_00337d60(unsigned int size, int alignment); };
extern Allocator DAT_0055dbb0;
extern "C" long __cdecl atol(const char*);
int __cdecl FUN_00337f20(int);
struct Owner;
typedef bool (__fastcall *Handler)(Owner*, Context*, void*, Parser*, Context*, int);
extern Handler DAT_004d9800[];
struct Owner { bool FUN_00336380(void** output, Parser* parser, Context* context, void* unused); };
bool Owner::FUN_00336380(void** output, Parser* parser, Context* context, void* unused) {
 const char* text = parser->FUN_00337980();
 if (!text) return false;
 int* type = context->type;
 int count = atol(text);
 int stride = FUN_00337f20(*type);
 char* data = (char*)DAT_0055dbb0.FUN_00337d60(count * stride + 4, 4);
 *output = data;
 *(int*)data = count;
 data += 4;
 for (int i=0; i<count; ++i) {
  parser->FUN_003379b0();
  if (!DAT_004d9800[*type](this, context, data, parser, context, 1)) return false;
  data += stride;
 }
 return true;
}
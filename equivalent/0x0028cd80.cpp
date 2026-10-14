// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 10/10)
// FUN_0028cd80 @ 0x0028cd80
struct Reader { void FUN_002647e0(void*, unsigned, unsigned, unsigned); };
struct Context { char pad[0x284]; Reader* reader; };
struct Pool_28cd80 { void* FUN_002888c0(unsigned, unsigned); };
struct Text_28cd80 { char data[8]; void FUN_0027b040(const char*); };
struct Result_28cd80 { char pad[8]; unsigned value; char pad2[8]; void* entries; Text_28cd80* names; Result_28cd80* FUN_0028c1a0(unsigned, Pool_28cd80*); };
extern "C" void* __cdecl FUN_0008d690(unsigned);
Result_28cd80* __stdcall FUN_0028cd80(Context* context, unsigned unused, Pool_28cd80* pool) {
 unsigned value, count;
 context->reader->FUN_002647e0(&value,1,4,1);
 context->reader->FUN_002647e0(&value,1,4,1);
 context->reader->FUN_002647e0(&count,1,4,1);
 void* memory = pool ? pool->FUN_002888c0(0x1c,7) : FUN_0008d690(0x1c);
 Result_28cd80* result = memory ? ((Result_28cd80*)memory)->FUN_0028c1a0(count,pool) : 0;
 result->value = value;
 context->reader->FUN_002647e0(result->entries,count,2,1);
 for(unsigned i=0;i<count;++i) {
 unsigned char length;
 char buffer[256];
 context->reader->FUN_002647e0(&length,1,1,1);
 context->reader->FUN_002647e0(buffer,length,1,1);
 buffer[length]=0;
 result->names[i].FUN_0027b040(buffer);
 }
 return result;
}
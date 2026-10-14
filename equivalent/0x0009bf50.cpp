// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_0009bf50 @ 0x0009bf50
struct Toggle { void FUN_000361c0(int); void FUN_00036140(int); };
struct Context { char pad[0x124]; Toggle* toggle; };
struct Arg_9bf50 { char pad[0x20]; Context* context; };
struct Item_9bf50 {
 virtual void slot0();
 virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void slot28();
 Item_9bf50* FUN_000ac3c0(); void FUN_000ac560(void*);
};
struct Helper_9bf50 { void FUN_00098480(Arg_9bf50*); };
void* __cdecl FUN_00263ea0(unsigned);
struct Target_9bf50 {
 char pad0[4]; unsigned flags; char pad8[8]; unsigned value; unsigned saved; unsigned char busy; char pad19[0xbc-0x19]; Helper_9bf50* helper; Item_9bf50* item;
 void FUN_0009a1e0(Arg_9bf50*); void FUN_000991b0(Arg_9bf50*,unsigned,Item_9bf50*,int,int);
 void run(Arg_9bf50* arg, void* input);
};
void Target_9bf50::run(Arg_9bf50* arg, void* input) {
 if (!input || busy || (flags & 8) || (flags & 64)) return;
 if (flags & 2) FUN_0009a1e0(arg);
 if (flags & 0x5e) return;
 if (flags & 32) helper->FUN_00098480(arg);
 flags = (flags & ~32u) | 8;
 saved = value;
 if (!item) {
  Item_9bf50* p = (Item_9bf50*)FUN_00263ea0(0x178);
  if (p) p = p->FUN_000ac3c0();
  item = p;
  p->slot0();
  item->slot28();
 }
 item->FUN_000ac560(input);
 Toggle* toggle = arg->context->toggle;
 if (toggle) { toggle->FUN_000361c0(1); toggle->FUN_00036140(1); }
 FUN_000991b0(arg,value,item,0,0);
}

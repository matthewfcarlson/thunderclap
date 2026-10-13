// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0020b0c0 @ 0x0020b0c0
struct String { unsigned short length, capacity; char* buffer; };
struct Attributes { unsigned root; String* name; unsigned flags; };
extern String DAT_004c9800;
extern int (__stdcall *DAT_003f2c04)(unsigned*, Attributes*);
extern int (__stdcall *DAT_003f2c00)(unsigned, String*, unsigned);
extern int (__stdcall *DAT_003f2be0)(unsigned);
struct Context { char pad[8]; unsigned value; };
extern Context* DAT_00010118;
extern void __stdcall FUN_0020b8d5(char*, const char*, unsigned);
extern int __stdcall FUN_00209daa(unsigned, char*, unsigned, unsigned, unsigned);
int __stdcall FUN_0020b0c0(unsigned a, unsigned b, unsigned c) {
 char output[520]; char buffer[520]; unsigned handle;
 Attributes attrs; attrs.root=0; attrs.name=&DAT_004c9800; attrs.flags=64;
 output[0]=0;
 const char* source="\\Device\\Cdrom0"; unsigned count=520;
 if(DAT_003f2c04(&handle,&attrs)>=0) {
  String text; text.length=0; text.capacity=520; text.buffer=buffer;
  int status=DAT_003f2c00(handle,&text,0);
  DAT_003f2be0(handle);
  if(status>=0) { source=buffer; count=(unsigned)text.length+1; if(count>520) count=520; }
 }
 FUN_0020b8d5(output,source,count);
 return FUN_00209daa(a+3,output,b,DAT_00010118->value,c);
}
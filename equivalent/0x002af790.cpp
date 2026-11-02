// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 10/10)
// FUN_002af790 @ 0x002af790
struct Header_2af790 { char pad[16]; int width; int height; };
struct Reader { void FUN_002647e0(unsigned char*, int, int, int); void FUN_00264510(int); };
struct Output_2af790 { virtual void init(int,int,int,int,int); virtual void row(unsigned char*); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual int finish(); };
extern unsigned char* __cdecl FUN_00266e00(int,int);
extern void __cdecl FUN_00267090(unsigned char*);
// equiv-conv: FUN_002af790 edi stack stack
extern "C" int __cdecl FUN_002af790(void * reader, void * header, void * output) {
 ((Output_2af790 *)output)->init(((Header_2af790 *)header)->width,((Header_2af790 *)header)->height,24,1,0);
 struct Locals { unsigned short unused; unsigned char b,c; unsigned char* buffer; int padding; int row; int width; int unused2; unsigned char a; } s;
 s.width=((Header_2af790 *)header)->width;
 s.padding=s.width & 3;
 s.buffer=FUN_00266e00(1,s.width*4);
 s.row=0;
 while(s.row<((Header_2af790 *)header)->height) {
  for(int x=0;x<s.width;++x) {
   ((Reader *)reader)->FUN_002647e0(&s.a,1,1,1);
   s.buffer[x*4]=s.a;
   ((Reader *)reader)->FUN_002647e0(&s.b,1,1,1);
   s.buffer[x*4+1]=s.b;
   ((Reader *)reader)->FUN_002647e0(&s.c,1,1,1);
   s.buffer[x*4+2]=s.c;
   s.buffer[x*4+3]=255;
  }
  ((Reader *)reader)->FUN_00264510(s.padding);
  ((Output_2af790 *)output)->row(s.buffer);
  ++s.row;
 }
 FUN_00267090(s.buffer);
 return ((Output_2af790 *)output)->finish();
}
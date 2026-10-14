// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000ebb90 @ 0x000ebb90
struct Item_ebb90 { char pad[0x24]; int a; int b; char tail[12]; void FUN_000f7930(); };
struct FUN_000e9240 { virtual void slot0(); char pad[0x13c]; unsigned char flag; char tail[15]; FUN_000e9240(int); };
struct TextSelector : FUN_000e9240 {
 virtual void slot0();
 int count, index;
 Item_ebb90 items[128];
 int f1d58, f1d5c; char gap60[8];
 float f1d68, f1d6c, f1d70; char gap74[8];
 int f1d7c,f1d80; unsigned char wrap; char gap85[3];
 int f1d88,f1d8c,f1d90,f1d94,f1d98,f1d9c,f1da0; unsigned int color;
 TextSelector(int arg, const char* name);
};
TextSelector::TextSelector(int arg,const char* name) : FUN_000e9240(arg) {
 count=0; index=0;
 for(int i=0;i<128;++i) items[i].FUN_000f7930();
 f1d5c=0; f1d68=1.0f; f1d6c=0.05f; f1d70=0.02f;
 f1d7c=0; f1d80=0; wrap=0; f1d88=0; f1d8c=0; f1d90=0; f1d98=0;
 f1d9c=-1; f1da0=-1; color=0xff000000;
 f1d58=0; count=0; index=0; f1d94=0; flag=0;
 if(name) { const char* s="wrap"; int j=0; for(;j<5;++j) if(name[j]!=s[j]) break; if(j==5) wrap=1; }
 for(int k=0;k<128;++k) { items[k].a=0; items[k].b=0; }
}

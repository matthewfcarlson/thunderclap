// STATUS: equivalent (tools/equiv.py level 3: 749 inputs, branch coverage 4/4)
// FUN_000ebe00 @ 0x000ebe00
struct Entry {
 char base[0x24];
 int a,b,c,d;
 unsigned char flag;
 char pad[3];
 void FUN_000f83c0(Entry*);
};
struct Object {
 char pad0[0x118];
 unsigned int block[10];
 char pad1[0x10];
 int x150,x154;
 Entry entries[128];
 int count;
 int x1d5c;
 char pad2[8];
 int x1d68;
 char pad3[0x10];
 int x1d7c,x1d80;
 void FUN_000e2940(Object*);
 void FUN_000e36c0();
 void FUN_000ebe00(Object* src);
};
void Object::FUN_000ebe00(Object* src) {
 FUN_000e2940(src);
 for(int j=0;j<10;++j) block[j]=src->block[j];
 FUN_000e36c0();
 count=src->count;
 x150=src->x150;
 x154=src->x154;
 x1d5c=src->x1d5c;
 x1d68=src->x1d68;
 x1d7c=src->x1d7c;
 x1d80=src->x1d80;
 for(int i=0;i<count;++i) {
 entries[i].FUN_000f83c0(&src->entries[i]);
 entries[i].a=src->entries[i].a;
 entries[i].b=src->entries[i].b;
 entries[i].c=src->entries[i].c;
 entries[i].d=src->entries[i].d;
 entries[i].flag=src->entries[i].flag;
 }
}
// STATUS: equivalent (tools/equiv.py level 3: 18773 inputs, branch coverage 8/8)
// FUN_0008cd80 @ 0x0008cd80
// cl-flags: /GS
struct Object {
 virtual void v0(); virtual void release(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void apply(void*); virtual void v18(); virtual void v19(); virtual void v20(); virtual void stop(); virtual void begin(); virtual int finish();
};
struct Entry_8cd80 { Object* primary; Object* secondary; char padding[192]; };
struct Output_8cd80 { int type; char data[260]; };
struct Manager_8cd80 {
 char pad[8]; Entry_8cd80* entries;
 int FUN_0008c590(int index, int arg, Output_8cd80* output);
 int FUN_0008cd80(int index,int arg);
};
int Manager_8cd80::FUN_0008cd80(int index,int arg) {
 Output_8cd80 output;
 Object* original = entries[index].primary;
 original->begin();
 if(entries[index].secondary) {
 entries[index].secondary->stop();
 Object** slot = &entries[index].secondary;
 if(*slot) { (*slot)->release(); *slot = 0; }
 }
 int result = FUN_0008c590(index,arg,&output);
 if(result == 0) {
 if(output.type != 3) result = 1;
 else { original->apply(output.data); result = original->finish(); }
 }
 return result;
}
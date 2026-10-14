// STATUS: equivalent (tools/equiv.py level 3: 25 inputs, branch coverage 10/10)
// FUN_0031bd30 @ 0x0031bd30
struct Resource_31bd30 { char pad[16]; unsigned divisor; };
extern unsigned DAT_004d3678;
extern unsigned DAT_004d3650[];
extern unsigned DAT_004d3664[];
extern unsigned DAT_003f335c;
struct Input_31bd30 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual bool v22(); virtual void v23(); virtual void v24();
 void FUN_00327d20(unsigned);
};
struct Manager_31bd30 { Resource_31bd30* FUN_00321da0(unsigned*,unsigned,unsigned,unsigned); void FUN_00324270(Input_31bd30*); };
struct Target_31bd30 {
 virtual void v0(unsigned);
 char p04[0x14]; unsigned count; unsigned zero; unsigned value;
 char p24[0x100]; Manager_31bd30* manager;
 char p128[0x10]; unsigned kindValue; unsigned kind; unsigned flags; unsigned unknown144; unsigned mode; unsigned lowFlags; Input_31bd30* input; Resource_31bd30* existing; Resource_31bd30* resource; unsigned extra;
 void FUN_0031bd30(unsigned,unsigned,Input_31bd30*,unsigned,unsigned);
};
void Target_31bd30::FUN_0031bd30(unsigned k,unsigned f,Input_31bd30* obj,unsigned e,unsigned arg) {
 extra=e;
 Resource_31bd30* r=existing;
 if (!r) r=manager->FUN_00321da0(&DAT_003f335c,k,f,0);
 resource=r;
 if(obj->v22()) obj->v24();
 if(flags & 0x80) manager->FUN_00324270(obj);
 if(f & 0x20) mode=1; else if(f & 0x4000) mode=(f>>15)&7; else mode=0;
 lowFlags=f&15;
 int q=(int)(DAT_004d3678/resource->divisor);
 count=(q/6)*6;
 kindValue=DAT_004d3650[k]; kind=k; flags=f; value=DAT_004d3664[k]; zero=0; input=obj;
 obj->FUN_00327d20(arg);
 v0(0);
}

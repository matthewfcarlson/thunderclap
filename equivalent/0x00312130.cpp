// STATUS: equivalent (tools/equiv.py level 3: 454 inputs, branch coverage 8/8)
// FUN_00312130 @ 0x00312130
struct Obj_312130;
struct Ref_312130 { virtual void AddRef() = 0; };
struct Context { char pad[0x88]; Ref_312130* ref; };
struct Child_312130 {
 virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
 virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0;
 virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void v11()=0;
 virtual void v12()=0; virtual void v13()=0; virtual void v14()=0; virtual void v15()=0;
 virtual void v16()=0; virtual void v17()=0; virtual void v18()=0; virtual void v19()=0;
 virtual void v20()=0; virtual void v21()=0; virtual void v22()=0; virtual void v23()=0;
 virtual void v24()=0; virtual void v25()=0; virtual void v26()=0;
 virtual Child_312130* Clone()=0;
 void FUN_0030a260(Obj_312130*);
};
extern void* __cdecl FUN_0008d6d0(unsigned);
struct Obj_312130 {
 char pad0[0x1f8]; Child_312130** children; int unknown1fc; int count; int unknown204;
 Ref_312130* ref208; int field20c; int field210; int field214; int field218;
 unsigned char field21c, field21d; char pad21e[2]; Ref_312130* ref220; int field224;
 int field228,field22c,field230;
 void FUN_002f75d0(Obj_312130*,Context*);
 void FUN_00311d50();
 void FUN_00312130(Obj_312130* dst, Context* context);
};
void Obj_312130::FUN_00312130(Obj_312130* dst, Context* context) {
 FUN_002f75d0(dst,context);
 dst->count=count;
 if(count>0) dst->children=(Child_312130**)FUN_0008d6d0((unsigned)count*4);
 for(int i=0;i<count;++i) {
   Child_312130* result=children[i]->Clone();
   dst->children[i]=result;
   dst->children[i]->FUN_0030a260(dst);
 }
 dst->field20c=0;
 dst->ref208=context->ref;
 dst->ref208->AddRef();
 dst->ref220=ref220;
 if(dst->ref220) dst->ref220->AddRef();
 dst->FUN_00311d50();
 dst->field228=field228;
 dst->field22c=field22c;
 int value=field230;
 dst->field214=0;
 dst->field218=0;
 dst->field230=value;
 dst->field21c=0;
 dst->field21d=1;
 field224=0;
}

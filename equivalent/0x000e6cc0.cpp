// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 10/10)
// FEThingsBase::vfunc_20 @ 0x000e6cc0
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern int DAT_004de94c;
struct Thing_e6cc0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual const char* v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 char pad[0xa74-4]; int state; void* resource; char pad2[0xa90-0xa7c]; float value; char pad3[12]; float result;
 void FUN_000e53e0(void*); void FUN_000e5440(int);
};
struct FEThingsBase {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39(); virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43(); virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void vfunc_47(); virtual void vfunc_48(int);
 char pad[0x1734-4]; char name[40]; Thing_e6cc0* current; char pad2[8]; Thing_e6cc0* pending; int active;
};
void FEThingsBase::vfunc_20() {
 if(current) {
 current->v15();
 Thing_e6cc0* t=current;
 void* r=t->resource;
 t->resource=0; t->state=0; t->result=t->value*0.0f;
 if(r) t->FUN_000e53e0(r);
 }
 if(!pending) { vfunc_48(1); vfunc_47(); }
 if(current) { const char* s=current->v8(); strncpy(name,s,40); } else name[0]=0;
 current=pending; pending=0;
 if(current) { current->v14(); active=1; current->FUN_000e5440(1); } else active=0;
 DAT_004de94c=0;
}
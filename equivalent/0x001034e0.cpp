// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001034e0 @ 0x001034e0
struct Vector { unsigned x,y,z; };
struct Entry { Vector position; int next; };
struct Table { char pad[0x14]; int count; Entry* FUN_00106160(int index); };
struct Transform { void FUN_00059a50(Vector* output); };
struct Object { char pad[0x10]; Transform* transform; };
struct Provider { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual Object* slot6(); };
struct Destination { void FUN_00104c60(unsigned,Vector*,Vector*,unsigned,unsigned,unsigned,unsigned); };
extern unsigned DAT_004dd700;
struct Target {
 char pad0[0x58]; Provider* provider; Destination* destination; Table* table; char pad1[0x54]; int index; unsigned parameter; unsigned char flag; char pad2[3]; unsigned option; char pad3[4]; unsigned a,b,c,d,e; char pad4[12]; unsigned f;
 bool FUN_001034e0();
};
bool Target::FUN_001034e0() {
 if (!table) return false;
 c=0; b=0; a=0; d=0; e=0; f=0;
 if(index<0) return false;
 Entry* entry=table->FUN_00106160(index);
 index=entry->next;
 if(index>=table->count) index=0;
 if(index==-1) return false;
 Object* object=provider->slot6();
 Vector origin; origin.x=0; origin.y=0; origin.z=0;
 object->transform->FUN_00059a50(&origin);
 entry=table->FUN_00106160(index);
 Vector position=entry->position;
 destination->FUN_00104c60(DAT_004dd700,&origin,&position,parameter,(unsigned)flag,option,0);
 return true;
}
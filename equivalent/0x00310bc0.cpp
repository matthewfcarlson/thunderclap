// STATUS: equivalent (tools/equiv.py level 3: 190 inputs, branch coverage 4/4)
// FUN_00310bc0 @ 0x00310bc0
struct Vec3 { float x,y,z; };
struct Work { char data[28]; void FUN_002fca90(); void FUN_002fcaa0(); };
struct Item { char pad0[128]; Vec3 position; char pad1[72]; Vec3 offset; };
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16();
 virtual void slot17(Vec3*,Vec3*,int,int,int);
 virtual bool slot18(Vec3*,Vec3*,Work*,int,int,int);
 virtual void slot19(int,int,int);
 virtual void slot20(Vec3*,Work*,int,int,int);
 char padding[0x1f8]; Item** items;
 void FUN_00310bc0(int index,float scale,Vec3* direction);
};
void Object::FUN_00310bc0(int index,float scale,Vec3* direction) {
 Item* item=items[index];
 Vec3 position; position.x=item->offset.x+item->position.x; position.y=item->offset.y+item->position.y; position.z=item->offset.z+item->position.z;
 Vec3 delta; delta.x=scale*direction->x; delta.y=scale*direction->y; delta.z=scale*direction->z;
 Work work; work.FUN_002fca90();
 slot17(&position,direction,0,index,-1);
 do { slot20(&position,&work,0,index,-1); } while (!slot18(&position,&delta,&work,0,index,-1));
 slot19(0,index,-1);
 work.FUN_002fcaa0();
}
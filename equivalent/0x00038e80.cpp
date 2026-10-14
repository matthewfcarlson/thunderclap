// STATUS: equivalent (tools/equiv.py level 3: 1390 inputs, branch coverage 18/18)
// FUN_00038e80 @ 0x00038e80
struct Vec3_38e80 { float x,y,z; };
struct Entry_38e80 {
 float x,y,z;
 Vec3_38e80 first,second;
 float time;
 void FUN_00037780(float a,float b,float c,const Vec3_38e80* d,const Vec3_38e80* e,float f);
};
struct Object {
 char pad0[0x338]; Object* next;
 char pad1[0x634-0x33c]; int count;
 Entry_38e80 entries[128];
 void target(float a,float b,float c,const Vec3_38e80* d,const Vec3_38e80* e,float f);
};
void Object::target(float a,float b,float c,const Vec3_38e80* d,const Vec3_38e80* e,float f) {
 Object* obj=this;
 while(obj->next) obj=obj->next;
 int count=obj->count;
 int index=0;
 bool insert=false;
 if(count>0) {
  do {
   if(f<obj->entries[index].time) { insert=true; break; }
   ++index;
  } while(index<obj->count);
 }
 if(!insert) {
  if(count<128) {
   obj->entries[count].FUN_00037780(a,b,c,d,e,f);
   ++obj->count;
  }
  return;
 }
 int end=count;
 if(end>=128) end=127;
 else obj->count=count+1;
 for(int i=end;i>index;--i) {
  Entry_38e80& src=obj->entries[i-1];
  obj->entries[i].FUN_00037780(src.x,src.y,src.z,&src.first,&src.second,src.time);
 }
 obj->entries[index].FUN_00037780(a,b,c,d,e,f);
}

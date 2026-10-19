// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 8/8)
// FUN_0007f450 @ 0x0007f450
typedef unsigned __int64 Key_7f450;
extern Key_7f450 __cdecl FUN_0027b020(int);
struct RandomResult { int FUN_00011330(int); };
extern RandomResult* __stdcall FUN_000964d0();
struct Vec3_7f450 { float x,y,z; };
struct Matrix { char data[64]; void FUN_0022b980(); void FUN_0022be40(Vec3_7f450*); void FUN_0022bc20(float,float,float); };
struct Object { virtual void start(); virtual void finish(); void FUN_00080e50(Matrix*); void FUN_00080c60(int); void FUN_00080c80(int); };
struct Record_7f450 { int count; char rest[12]; };
struct Owner_7f450 {
 char pad[0x34b0];
 union { Record_7f450 records[256]; struct { char gap[0x98]; int count; Object* objects[256]; } list; };
 int FUN_00079220(Key_7f450);
 Object* FUN_0007f310(int,int,int,int);
 void FUN_0007b380(Object*);
 void target(int,int,int,Vec3_7f450,float,float,float);
};
void Owner_7f450::target(int name,int arg,int flags,Vec3_7f450 position,float x,float y,float z) {
 Key_7f450 key=FUN_0027b020(name);
 int index=FUN_00079220(key);
 if ((index<0 || list.objects[index]==0) && list.count>0) {
  int a=FUN_000964d0()->FUN_00011330(list.count-1);
  int b=FUN_000964d0()->FUN_00011330(records[a].count-1);
  Object* object=FUN_0007f310(name,arg,a,b);
  if(object) {
   object->start();
   Matrix matrix;
   matrix.FUN_0022b980();
   matrix.FUN_0022be40(&position);
   matrix.FUN_0022bc20(x*0.0174532924f,y*0.0174532924f,z*0.0174532924f);
   object->FUN_00080e50(&matrix);
   object->FUN_00080c60(flags);
   object->FUN_00080c80(1);
   FUN_0007b380(object);
   object->finish();
  }
 }
}
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0007f450 @ 0x0007f450
typedef unsigned __int64 Key;
extern Key __cdecl FUN_0027b020(int);
struct RandomResult { int FUN_00011330(); };
extern RandomResult* __stdcall FUN_000964d0(int);
struct Vec3 { float x,y,z; };
struct Matrix { char data[64]; void FUN_0022b980(); void FUN_0022be40(Vec3*); void FUN_0022bc20(float,float,float); };
struct Object { virtual void start(); virtual void finish(); void FUN_00080e50(Matrix*); void FUN_00080c60(int); void FUN_00080c80(int); };
struct Record { int count; char rest[12]; };
struct Owner {
 char pad[0x34b0];
 union { Record records[256]; struct { char gap[0x98]; int count; Object* objects[256]; } list; };
 int FUN_00079220(Key);
 Object* FUN_0007f310(int,int,int,int);
 void FUN_0007b380(Object*);
 void target(int,int,int,Vec3,float,float,float);
};
void Owner::target(int name,int arg,int flags,Vec3 position,float x,float y,float z) {
 Key key=FUN_0027b020(name);
 int index=FUN_00079220(key);
 if ((index<0 || list.objects[index]==0) && list.count>0) {
  int a=FUN_000964d0(list.count-1)->FUN_00011330();
  int b=FUN_000964d0(records[a].count-1)->FUN_00011330();
  Object* object=FUN_0007f310(name,arg,a,b);
  if(object) {
   object->start();
   Matrix matrix;
   matrix.FUN_0022b980();
   matrix.FUN_0022be40(&position);
   matrix.FUN_0022bc20(x*0.0174533f,y*0.0174533f,z*0.0174533f);
   object->FUN_00080e50(&matrix);
   object->FUN_00080c60(flags);
   object->FUN_00080c80(1);
   FUN_0007b380(object);
   object->finish();
  }
 }
}
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::PhysicsPropertiesLoader::vfunc_5 @ 0x002f2970
typedef unsigned __int64 Key;
struct Reader { void FUN_002647e0(void*, unsigned, unsigned, unsigned); };
struct Context { char pad[0x284]; Reader* reader; };
Key __cdecl FUN_0027b020(const char*);
struct Manager { void FUN_002f27c0(Key, float, float, float, float); };
extern Manager* DAT_00554c30;
namespace physics {
struct PhysicsPropertiesLoader {
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
virtual void vfunc_5(unsigned, unsigned, Context*, unsigned);
};
void PhysicsPropertiesLoader::vfunc_5(unsigned, unsigned, Context* context, unsigned) {
struct Data { char pad[3]; unsigned char length; float a,c,d,b; char name[256]; } data;
context->reader->FUN_002647e0(&data.length,1,1,1);
unsigned count=data.length;
context->reader->FUN_002647e0(data.name,count,1,1);
data.name[count]=0;
context->reader->FUN_002647e0(&data.a,1,4,1);
context->reader->FUN_002647e0(&data.b,1,4,1);
context->reader->FUN_002647e0(&data.d,1,4,1);
context->reader->FUN_002647e0(&data.a,1,4,1);
context->reader->FUN_002647e0(&data.c,1,4,1);
float x=data.a*0.5f+1.0f, y=data.b+data.b, z=data.c*-1.0f, w=data.d+data.d;
Key key=FUN_0027b020(data.name);
DAT_00554c30->FUN_002f27c0(key,x,y,z,w);
}
}
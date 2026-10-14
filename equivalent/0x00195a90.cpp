// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00195a90 @ 0x00195a90
struct Owner { char pad[0x18]; char position[0x60]; unsigned int value; };
struct Matrix { char data[64]; void FUN_0022b980(); };
struct Manager { unsigned int FUN_00283a40(void*, Matrix*, float, float); };
Manager* __cdecl FUN_0027f250();
struct FUN_001b6800 { virtual void dummy(); unsigned int a,b,value,d,e; FUN_001b6800(); };
namespace hulkfight { namespace motion {
struct ProjectileEffect : FUN_001b6800 {
 Owner* owner; unsigned int handle; unsigned int fields[10]; float time; unsigned int last;
 virtual void dummy();
 ProjectileEffect(Owner*);
};
}}
hulkfight::motion::ProjectileEffect::ProjectileEffect(Owner* p) {
 owner=0; fields[0]=0; fields[1]=0; fields[2]=0; fields[3]=0; fields[4]=0; fields[5]=0; fields[6]=0; fields[7]=0; fields[8]=0; fields[9]=0; time=-1.0f; last=0;
 owner=p; value=p->value;
 Matrix m; m.FUN_0022b980();
 Manager* manager=FUN_0027f250();
 handle=manager->FUN_00283a40(owner->position,&m,-1.0f,1.0f);
}

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001dc4a0 @ 0x001dc4a0
struct Vec { float x,y,z; };
extern Vec DAT_004c6194;
struct Result { void FUN_0022c3b0(); };
struct Object { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual Result* query(Vec*,Vec*); };
struct Transform { char data[16]; void FUN_0022b4d0(Vec*,Vec*); };
struct Part { void FUN_001db820(Transform*); };
struct Entry { char pad[16]; Part part; char p2[7]; Object* object; char p3[6]; short index; char p4[4]; };
struct Flag { unsigned char bits; char pad[19]; };
extern float __cdecl FUN_00224ea0(float,float);
struct Owner { char pad[0x608]; Entry entries[1932]; int FUN_001dbfe0(int); float target(int); };
float Owner::target(int id) { Vec out; Transform temp; int n=FUN_001dbfe0(id); if(n<0) return 0.0f; Entry& e=entries[n]; Flag* flags=(Flag*)this; if((flags[e.index+0x104e].bits&1) && e.object) { e.object->query(&DAT_004c6194,&out)->FUN_0022c3b0(); } else { e.part.FUN_001db820(&temp); temp.FUN_0022b4d0(&DAT_004c6194,&out); } return FUN_00224ea0(out.x,out.z)*57.2957763671875f; }
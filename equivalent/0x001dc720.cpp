// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 10/10)
// FUN_001dc720 @ 0x001dc720
struct Vec { float x,y,z; bool FUN_0022d2b0(const Vec*, float); };
struct Motion {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(int);
 void FUN_002f5a20(Vec*);
};
struct State { char pad[0x70]; Motion* motion; };
struct Object { State* FUN_001d72e0(); Vec* FUN_001d77c0(); void FUN_001d7510(); };
struct Record { char pad[0x18]; Object* object; char extra[6]; short index; char tail[4]; };
struct Flag { unsigned char bits; char pad[19]; };
struct Manager {
 char pad[0x608]; Record records[2048]; char gap[16]; Flag flags[32768];
 int FUN_001dbfe0(int);
 bool FUN_001dc720(int id, Vec position);
};
bool Manager::FUN_001dc720(int id, Vec position) {
 int i = FUN_001dbfe0(id);
 if(i < 0) return false;
 Record* r = &records[i];
 if(!(flags[r->index].bits & 1) || !r->object) return false;
 Motion* motion = r->object->FUN_001d72e0()->motion;
 if(motion) { motion->v6(0); motion->FUN_002f5a20(&position); }
 else { Vec* destination = r->object->FUN_001d77c0(); *destination = position; }
 Vec zero; zero.x=0.0f; zero.y=0.0f; zero.z=0.0f;
 if(!position.FUN_0022d2b0(&zero, 0.00001f)) r->object->FUN_001d7510();
 return true;
}
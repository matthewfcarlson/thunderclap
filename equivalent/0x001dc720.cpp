// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 10/10)
// FUN_001dc720 @ 0x001dc720
#include "gen/global.h"
struct Vec_1dc720 { float x,y,z; bool FUN_0022d2b0(const Vec_1dc720*, float); };
struct Motion_1dc720 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(int);
 void FUN_002f5a20(Vec_1dc720*);
};
struct State_1dc720 { char pad[0x70]; Motion_1dc720* motion; };
struct CSPManager_nv_1dc720 {
    State_1dc720* FUN_001d72e0();
    Vec_1dc720* FUN_001d77c0();
    void FUN_001d7510();
};
struct Record_1dc720 { char pad[0x18]; CSPManager* object; char extra[6]; short index; char tail[4]; };
struct Flag_1dc720 { unsigned char bits; char pad[19]; };
struct Manager_1dc720 {
 char pad[0x608]; Record_1dc720 records[2048]; char gap[16]; Flag_1dc720 flags[32768];
 int FUN_001dbfe0(int);
 bool FUN_001dc720(int id, Vec_1dc720 position);
};
bool Manager_1dc720::FUN_001dc720(int id, Vec_1dc720 position) {
 int i = FUN_001dbfe0(id);
 if(i < 0) return false;
 Record_1dc720* r = &records[i];
 if(!(flags[r->index].bits & 1) || !r->object) return false;
 Motion_1dc720* motion = ((CSPManager_nv_1dc720*)(r->object))->FUN_001d72e0()->motion;
 if(motion) { motion->v6(0); motion->FUN_002f5a20(&position); }
 else { Vec_1dc720* destination = ((CSPManager_nv_1dc720*)(r->object))->FUN_001d77c0(); *destination = position; }
 Vec_1dc720 zero; zero.x=0.0f; zero.y=0.0f; zero.z=0.0f;
 if(!position.FUN_0022d2b0(&zero, 0.00001f)) ((CSPManager_nv_1dc720*)(r->object))->FUN_001d7510();
 return true;
}
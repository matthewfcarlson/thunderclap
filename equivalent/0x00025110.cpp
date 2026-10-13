// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 18/18)
// FUN_00025110 @ 0x00025110
struct Vec3 { float x,y,z; };
struct Vec4 { float x,y,z,w; };
struct Position { void FUN_000382c0(Vec3*); };
struct Entity { char pad[0x148]; Position* position; void FUN_001d69f0(Vec3*); };
struct Selection { char pad[8]; void* object; int type; };
struct Source { char pad[0x328]; Selection* selection; unsigned char enabled; };
struct Manager { unsigned char FUN_001c4050(Vec4*); };
extern Manager* __cdecl FUN_001c3d90();
extern unsigned char __cdecl FUN_00096b50(Selection*,Vec3*,float*);
struct Actor { char pad0[0x124]; Source* source; char pad1[0x330-0x128]; Vec3 position; float timerReset; float timer; char pad2[0x350-0x344]; unsigned char active; unsigned char inactive; void FUN_00025110(float); };
void Actor::FUN_00025110(float delta) {
 Source* s=source; active=0; inactive=0;
 if (!s) return;
 if (timer >= 0.0f) timer -= delta; else timerReset=5.0f;
 Selection* selection=s->selection;
 if (!selection || !s->enabled) return;
 Vec3 point;
 if (!FUN_00096b50(selection,&point,&delta)) return;
 Manager* manager=FUN_001c3d90();
 Vec4 query; query.x=point.x; query.y=point.y; query.z=point.z; query.w=1.0f;
 unsigned char blocked=manager->FUN_001c4050(&query);
 if (selection->type==5) { Entity* e=(Entity*)selection->object; if (e->position) e->position->FUN_000382c0(&position); else e->FUN_001d69f0(&position); }
 else if (selection->type==1) ((Position*)selection->object)->FUN_000382c0(&position);
 if (!blocked) inactive=1; else active=1;
}

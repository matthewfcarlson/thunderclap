typedef unsigned char byte;
extern int vf;
class Helper { public: void clean(); };
class Base { public: void init(); };
void thunk(void*);
namespace hulkfight { namespace motion {
class WallRunTrack { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual WallRunTrack* vfunc_5(byte); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); char pad[0x38]; };
WallRunTrack* WallRunTrack::vfunc_5(byte param) {
 *(int*)this = (int)&vf;
 ((Helper*)((char*)this+0x48))->clean();
 ((Helper*)((char*)this+0x40))->clean();
 ((Helper*)((char*)this+0x38))->clean();
 ((Base*)this)->init();
 if (param & 1) thunk(this);
 return this;
}
}}

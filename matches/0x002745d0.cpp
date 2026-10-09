class Req { public: virtual void v0(); virtual void v1(); };
class Dev { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual unsigned g(); unsigned MakeValue(); };
struct Ctx { char pad0[4]; Req sub; char pad1[4]; Dev* dev; char pad2[8]; unsigned value; };
class DriveFormatRequest { public: virtual void vfunc_0(); virtual unsigned vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); char pad[4]; Ctx* drive; };
unsigned DriveFormatRequest::vfunc_1() {
 Dev* d = drive->dev;
 unsigned x = d->g();
 unsigned y = d->MakeValue();
 drive->sub.v0();
 drive->value = y;
 drive->sub.v1();
 return x;
}
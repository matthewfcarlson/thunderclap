class Thing { public: char pad[12]; int y; int z; void Init(int); Thing(int,int,int); };
extern void Finish();
Thing::Thing(int x, int yy, int zz) {
    Init(x);
    *(int*)this = 0x42ba20;
    y = yy;
    z = zz;
    Finish();
}
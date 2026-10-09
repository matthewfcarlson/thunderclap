class CProjectile {
  public:
    int a;
    int b;
    int c;
    int d;
    unsigned char e;
    int f;
    CProjectile();
};
extern int projectile_vftable;
CProjectile::CProjectile() {
    b = 0;
    *(int*)this = (int)&projectile_vftable;
    c = -1;
    d = 0;
    e = 0;
    f = 0;
}
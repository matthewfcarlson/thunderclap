// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 0/0)
// FUN_00104c60 @ 0x00104c60
struct Vec_104c60 { int x, y, z; };
struct Sub_104c60 { char pad[0x75]; char v75; };
struct Obj_104c60 {
 char pad0[0x60]; Sub_104c60* sub; char pad1[4];
 int v68, v6c;
 Vec_104c60 p70, p7c;
 char v88, v89, pad2[2];
 int v8c; char v90; char pad3[3];
 int v94, v98;
 char pad4[0xd8 - 0x9c];
 int vd8, vdc, ve0, ve4;
 void Reset(int a, int b, const Vec_104c60* pos, int c, char d, int e, int unused);
};
void Obj_104c60::Reset(int, int, const Vec_104c60* pos, int c, char d, int e, int) {
 v6c = 0;
 sub->v75 = 0;
 v68 = 0;
 p70.x = pos->x; p70.y = pos->y; p70.z = pos->z;
 p7c.x = pos->x; p7c.y = pos->y; p7c.z = pos->z;
 v8c = c;
 v90 = d;
 v89 = 0;
 v88 = 1;
 v94 = e;
 v98 = e;
 ve0 = 0; vdc = 0; vd8 = 0; ve4 = 0;
}

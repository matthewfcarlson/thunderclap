// STATUS: equivalent (tools/equiv.py level 3: 18271 inputs, branch coverage 0/0)
// FUN_0021ad80 @ 0x0021ad80
// FUN_0021ad80 @ 0x0021ad80
struct Values { unsigned int a,b,c,d; };
// equiv-conv: FUN_0021acc0 esi
void FUN_0021acc0(Values *);
void __cdecl FUN_0021ab30(unsigned int, unsigned int, Values *);
int __cdecl FUN_0021ad80(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5)
{
    Values v;
    v.a = p1;
    v.b = p3;
    v.c = p4;
    v.d = p5;
    FUN_0021acc0(&v);
    FUN_0021ab30(p2, 0, &v);
    return 1;
}

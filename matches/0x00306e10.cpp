struct Triple { int a,b,c; };
class Target {
public:
 int x0,x1,x2,x3,x4,x5,x6,x7;
 unsigned char flag;
 int x9;
 void Set(Triple* a, Triple* b, int c, int d, unsigned char e, int f);
};
void Target::Set(Triple* a, Triple* b, int c, int d, unsigned char e, int f) {
 x0=a->a; x1=a->b; x2=a->c;
 x3=b->a; x4=b->b; x5=b->c;
 x6=c; x7=d; flag=e; x9=f;
}
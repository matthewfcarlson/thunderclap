class MemoryDlAllocator {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual bool f9(int*,int*,int*,int*); virtual void f10(); virtual void f11(); virtual void f12();
 char pad[0x10]; int a; char pad2[0x490-0x18]; int c; int b; int d;
};
bool MemoryDlAllocator::f9(int*p1,int*p2,int*p3,int*p4){if(p1)*p1=a-b;if(p2)*p2=0;if(p3)*p3=c;if(p4)*p4=d;return true;}
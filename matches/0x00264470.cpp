class Ref { public: virtual void f0(); virtual void f1(); virtual void f2(); };
class LoadStream { public: virtual void f0(); virtual void f1(); virtual LoadStream* f2(unsigned char); char pad[4]; Ref* mRef; char pad2[20]; void* a; void* b; };
extern int streamvt, refvt;
void Init(); void Free(void*); void Destroy(LoadStream*);
LoadStream* LoadStream::f2(unsigned char flag) {
 *(int*)this=(int)&streamvt;
 Init();
 if (mRef) mRef->f1();
 if (a) Free(a);
 if (b) Free(b);
 *(int*)this=(int)&refvt;
 if (flag & 1) Destroy(this);
 return this;
}
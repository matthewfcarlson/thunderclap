class Ref { public: virtual void f0(); virtual void f1(); };
class CollisionObject { public: unsigned long vptr; char pad4[0x1c]; Ref *mRef; char pad24[0xc]; void *mPtr; char pad34[4]; char sub[0x10]; void destroy(); };
class H38 { public: void run(); };
class H10 { public: void run(); };
class Htail { public: void run(); };
extern void thunk(void*);
void CollisionObject::destroy() {
 Ref *r=mRef; vptr=0x431b08;
 if(r) r->f1();
 ((H38*)sub)->run();
 if(mPtr) thunk((char*)mPtr-4);
 ((H10*)((char*)this+0x10))->run();
 ((Htail*)this)->run();
}
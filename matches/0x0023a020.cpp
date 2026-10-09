// Same code shape as 0x00237160 (propagated; names are from that function)
class Obj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual bool Check(); virtual long long Pair(); virtual void v15(); virtual void Act(int,int); virtual void Done(); };
class Owner { public: bool Target(int a, int b, int c, Obj* obj); void Work(int, Obj*, int); };
bool Owner::Target(int a, int b, int c, Obj* obj) {
    if (!obj->Check()) return false;
    unsigned long long v = (unsigned long long)obj->Pair();
    if ((unsigned int)v != (unsigned int)a) return false;
    if ((unsigned int)(v >> 32) != (unsigned int)b) return false;
    obj->Act(a, b);
    Work(c, obj, -1);
    obj->Done();
    return true;
}

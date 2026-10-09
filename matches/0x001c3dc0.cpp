class First { public: void Cleanup(); };
class Obj { public: virtual void v0(); virtual void v1(); };
void thunk_FUN_00267090(First*);
class Target { public: First* volatile mFirst; char pad[0x6c]; Obj * volatile m70; Obj * volatile m74; void F(); };
void Target::F() {
    First* p = mFirst;
    if (p) { p->Cleanup(); thunk_FUN_00267090(p); }
    mFirst = 0;
    Obj* a = m70;
    if (a) { a->v1(); m70 = 0; }
    Obj* b = m74;
    if (b) { b->v1(); m74 = 0; }
}
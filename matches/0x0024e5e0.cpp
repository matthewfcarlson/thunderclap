typedef void* X_24e5e0;
X_24e5e0 __cdecl WrapThing(X_24e5e0, int);
X_24e5e0 __fastcall MakeThing(void*);
struct Obj_24e5e0 {
    X_24e5e0 value;
    X_24e5e0 Run(void*);
};
X_24e5e0 Obj_24e5e0::Run(void* arg) {
    X_24e5e0 temp = MakeThing(arg);
    value = WrapThing(temp, 0);
    return this;
}
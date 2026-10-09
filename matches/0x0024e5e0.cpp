typedef void* X;
X __cdecl WrapThing(X, int);
X __fastcall MakeThing(void*);
struct Obj {
    X value;
    X Run(void*);
};
X Obj::Run(void* arg) {
    X temp = MakeThing(arg);
    value = WrapThing(temp, 0);
    return this;
}
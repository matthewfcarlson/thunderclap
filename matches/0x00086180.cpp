struct Obj {
    void Call(int);
};
extern Obj* gObject;
void __stdcall Target(int a, int b, int c, int d) {
    if (gObject)
        gObject->Call(a);
}
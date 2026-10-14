struct Obj_86180 {
    void Call(int);
};
extern Obj_86180* gObject_86180;
void __stdcall Target(int a, int b, int c, int d) {
    if (gObject_86180)
        gObject_86180->Call(a);
}
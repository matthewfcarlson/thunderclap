struct Obj_2211e0 {
    char pad[12];
    int a;
    int b;
};
extern "C" int __cdecl FUN_00221190(void *, void *);
void FUN_00220d90(void*, Obj_2211e0*);
extern "C" void FUN_002211e0(void* p, void * q) {
    if (((Obj_2211e0 *)q)->a != ((Obj_2211e0 *)q)->b)
        FUN_00221190(p, (Obj_2211e0 *)((Obj_2211e0 *)q));
    else
        FUN_00220d90(p, ((Obj_2211e0 *)q));
}
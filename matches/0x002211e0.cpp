struct Obj { char pad[12]; int a; int b; };
void FUN_00221190(void*, Obj*);
void FUN_00220d90(void*, Obj*);
void FUN_002211e0(void* p, Obj* q) {
    if (q->a != q->b) FUN_00221190(p, q);
    else FUN_00220d90(p, q);
}
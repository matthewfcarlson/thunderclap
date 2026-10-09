class Obj { public: char pad[8]; int a; int b; int c; int d; char e; void first(); void second(int,int); };
extern int f2(int,int);
Obj* __fastcall target(Obj* self, void*) {
    self->first();
    self->second(0,0);
    self->a=0;
    self->b=f2(0,0);
    self->c=999;
    self->d=0;
    self->e=0;
    return self;
}
class A { public: char pad[0x70]; void* m70; void* m74; };
extern void __fastcall thunk(void*);
extern void __fastcall other(void*);
void __fastcall target(A* self) {
    void* p = self->m70;
    if (p && *(int*)((char*)p + 0x24) == 2) thunk(p);
    void* q = self->m74;
    if (q) other(*(void**)((char*)q + 0x20));
}
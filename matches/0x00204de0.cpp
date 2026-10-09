struct Owner {
    char pad[0x58c];
    void* ptr;
    char pad2[4];
    int a;
    int b;
};
struct Item {
    char pad[0x56];
    void Destroy();
};
void __cdecl FreeArray(void*);
void __fastcall target(Owner* self) {
    char* p = (char*)self->ptr;
    if (p != 0) {
        int n = *(int*)(p - 4);
        Item* q = (Item*)(p + n * 0x56);
        while (--n >= 0) {
            q = (Item*)((char*)q - 0x56);
            q->Destroy();
        }
        FreeArray(p - 4);
    }
    self->ptr = 0;
    self->a = 0;
    self->b = 0;
}
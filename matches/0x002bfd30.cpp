struct Base {
    void Finish();
};
struct Image {
    int vf;
    char pad[0x20];
    int m24;
};
extern void __cdecl Thunk(int);
void Image_Init(Image*);
void __fastcall Image_Init(Image* self, void*) {
    int x = self->m24;
    self->vf = 0x42ea40;
    Thunk(x);
    ((Base*)self)->Finish();
}
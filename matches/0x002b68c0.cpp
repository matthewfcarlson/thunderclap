extern "C" char DAT_0042e654[];
class ShadowMeshBufferLoader {
  public:
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};
extern "C" int __cdecl alloc_mem(int);
int __fastcall init_obj(int);
ShadowMeshBufferLoader* __fastcall target(ShadowMeshBufferLoader* self) {
    self->b = 0;
    self->c = 0x10023;
    self->d = 0;
    self->e = 0;
    self->a = ((int)DAT_0042e654);
    int p = alloc_mem(0x2c);
    self->f = p ? init_obj(p) : 0;
    return self;
}

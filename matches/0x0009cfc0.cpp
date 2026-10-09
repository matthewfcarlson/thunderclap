// Same code shape as 0x0002f4d0 (propagated; names are from that function)
struct Vector {
    int a, b, c;
};
class CActorManager;
class Closure2 {
  public:
    char pad[0x1c];
    void(__fastcall* fn)(CActorManager*, Closure2*, Vector, float);
    CActorManager* object;
    void vfunc_2(void* unused, int* p, void* unused2);
};
void Closure2::vfunc_2(void* unused, int* p, void* unused2) {
    fn(object, this, *(Vector*)p, *(float*)(p + 3));
}

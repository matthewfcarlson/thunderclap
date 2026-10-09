typedef unsigned int u32;
namespace pure3d {
struct Sub {
    void update();
};
struct Block {
    u32 v[16];
};
struct Camera {
    char pad[0x8c];
    Block field;
    char flag;
    void vfunc_21(const u32* p);
};
void Camera::vfunc_21(const u32* p) {
    field = *(const Block*)p;
    flag = 1;
    *(Block*)((char*)this + 0x4c) = field;
    ((Sub*)((char*)this + 0x4c))->update();
}
} // namespace pure3d

typedef unsigned int u32_292e70;
namespace pure3d {
struct Sub_292e70 {
    void update();
};
struct Block_292e70 {
    u32_292e70 v[16];
};
struct Camera {
    char pad[0x8c];
    Block_292e70 field;
    char flag;
    void vfunc_21(const u32_292e70* p);
};
void Camera::vfunc_21(const u32_292e70* p) {
    field = *(const Block_292e70*)p;
    flag = 1;
    *(Block_292e70*)((char*)this + 0x4c) = field;
    ((Sub_292e70*)((char*)this + 0x4c))->update();
}
} // namespace pure3d

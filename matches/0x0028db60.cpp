namespace math {
struct Quaternion {
    float x, y, z, w;
};
struct CompressedQuaternion3 {
    unsigned char bytes[3];
    Quaternion* FUN_0028dbb0(Quaternion* result);
};
} // namespace math
namespace pure3d {
struct CompressedQuaternionChannel {
    char pad[0x14];
    short* frames;
    math::CompressedQuaternion3* values;
    void vfunc_3(int index, float* time, math::Quaternion* rotation);
};
} // namespace pure3d
void pure3d::CompressedQuaternionChannel::vfunc_3(int index, float* time, math::Quaternion* rotation) {
    *time = (float)frames[index];
    math::Quaternion temp;
    math::Quaternion* decoded = values[index].FUN_0028dbb0(&temp);
    *rotation = *decoded;
}
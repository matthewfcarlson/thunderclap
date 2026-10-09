struct CompressedQuaternion4 { unsigned int x[4]; };
struct PackedQ { unsigned int v; CompressedQuaternion4* Decode(CompressedQuaternion4* tmp); };
class CompressedQuaternionChannel {
public:
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3(int index, float* time, CompressedQuaternion4* out);
 char pad[0x10];
 short* indices;
 PackedQ* data;
};
void CompressedQuaternionChannel::vfunc_3(int index, float* time, CompressedQuaternion4* out) {
 int value = indices[index];
 *time = (float)value;
 CompressedQuaternion4 temp;
 CompressedQuaternion4* p = data[index].Decode(&temp);
 *out = *p;
}

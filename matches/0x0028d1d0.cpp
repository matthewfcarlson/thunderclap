struct CompressedQuaternion8 { unsigned char data[8]; float* decode(float*); };
struct RotationChannel { virtual void a(); virtual void b(); virtual void c(); };
struct Quaternion { float a,b,c,d; };
struct CompressedQuaternionChannel : RotationChannel { char pad[0x10]; short* indices; CompressedQuaternion8* values; virtual void f0(); virtual void f1(); virtual void f3(int, float*, Quaternion*); };
void CompressedQuaternionChannel::f3(int index, float* time, Quaternion* out) {
 *time = (float)indices[index];
 float temp[4];
 float* p = (values + index)->decode(temp);
 *(Quaternion*)out = *(Quaternion*)p;
}
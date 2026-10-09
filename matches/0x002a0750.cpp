class LoadObject { public: virtual void v0(); virtual void v1(); };
namespace pure3d {
class Light : public LoadObject {
public:
 char data[0x0c]; unsigned char flag; char pad[0x13]; int value;
 virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(int); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(int);
};
void Light::vfunc_5(int x) { flag=1; value=x; vfunc_9(1); }
}
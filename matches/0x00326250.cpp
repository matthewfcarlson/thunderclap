namespace pure3d {
class pddiObject {
public:
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
};
class pddiTexture : public pddiObject {
public:
 virtual void vfunc_15();
 virtual void vfunc_20();
};
class d3dTexture : public pddiTexture {
public:
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual void vfunc_6();
 virtual unsigned int vfunc_7();
 virtual void vfunc_8();
 virtual void vfunc_9();
 virtual void vfunc_10();
 virtual void vfunc_11();
 virtual void vfunc_12();
 virtual void vfunc_13();
 virtual void vfunc_14();
 virtual void vfunc_16();
 virtual void vfunc_17();
 virtual void vfunc_18();
 virtual void vfunc_19();
 char pad[0xdc - 4];
 unsigned int field;
};
unsigned int d3dTexture::vfunc_7() { return field; }
}
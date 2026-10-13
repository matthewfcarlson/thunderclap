// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e9ec0 @ 0x000e9ec0
struct FUN_000e9240 {
    FUN_000e9240(int arg);
    virtual void slot0();
    char pad04[0x74];
    unsigned values78[3];
    char pad84[0xcc];
    float range150;
    unsigned state154;
    unsigned state158;
    unsigned state15c;
    float range160;
    float range164;
    unsigned state168;
    unsigned state16c;
    char pad170[12];
    unsigned state17c;
    unsigned state180;
    unsigned state184;
    unsigned state188;
    unsigned state18c;
    unsigned state190;
    unsigned states194[20];
    unsigned color1e4;
    unsigned color1e8;
    unsigned color1ec;
    float scale1f0;
    float scale1f4;
};
struct HSlider : FUN_000e9240 {
    virtual void slot0();
    HSlider(int arg);
};
HSlider::HSlider(int arg) : FUN_000e9240(arg) {
    state184=state188=state18c=state190=0;
    color1e4=color1e8=0xffffffff;
    color1ec=0xff000000;
    state154=state15c=state16c=0;
    values78[0]=values78[1]=values78[2]=0;
    state17c=state180=0;
    range160=range164=range150=100.0f;
    state158=state168=1;
    scale1f0=scale1f4=1.0f;
    for (int i=0;i<20;++i) states194[i]=0;
}

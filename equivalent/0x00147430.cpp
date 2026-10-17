// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00147430 @ 0x00147430
namespace hulkfight { namespace motion {
struct BaseTrack {
    virtual void slot0();
    BaseTrack();
    char pad[8];
};
struct GrappleThrowTrack : BaseTrack {
    virtual void slot0();
    void* field_c;
    void* field_10;
    void* field_14;
    float field_18;
    float field_1c;
    float field_20;
    float field_24;
    float field_28;
    float field_2c;
    int field_30;
    int field_34;
    int field_38;
    float field_3c;
    GrappleThrowTrack();
};
GrappleThrowTrack::GrappleThrowTrack() {
    field_c = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = -1.0f;
    field_30 = 0;
    field_34 = 0;
    field_38 = 0;
    field_1c = 10.0f;
    field_20 = 100.0f;
    field_24 = 10.0f;
    field_28 = 100.0f;
    field_2c = 1.57079637f;
    field_3c = 1.0f;
}
}}
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00069c50 @ 0x00069c50
struct FUN_00236d40 { virtual void placeholder(); char baseData[4]; FUN_00236d40(); };
struct CAutoTargetTrack : FUN_00236d40 {
    int flag;
    int unknownC;
    float a, b, c, d;
    int enabled, pointer24, pointer28, index, pointer30, pointer34;
    unsigned char byte38;
    CAutoTargetTrack();
};
CAutoTargetTrack::CAutoTargetTrack() {
    unknownC = 0;
    pointer24 = 0;
    pointer28 = 0;
    pointer30 = 0;
    pointer34 = 0;
    byte38 = 0;
    a = -1.0f;
    b = 3.14159274f;
    c = 1.57079637f;
    d = 10.0f;
    enabled = 1;
    index = -5;
    flag = 1;
}

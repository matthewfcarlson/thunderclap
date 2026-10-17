// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00069a80 @ 0x00069a80
struct BaseTrack {
    virtual void update();
    char reserved[4];
    BaseTrack();
};

struct CMoveAddYTrack : BaseTrack {
    int enabled;
    int other;
    float scale;
    float weight;
    int state;
    CMoveAddYTrack();
};

CMoveAddYTrack::CMoveAddYTrack() {
    scale = 1.0f;
    weight = 1.0f;
    other = 0;
    state = 0;
    enabled = 1;
}

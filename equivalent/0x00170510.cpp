// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00170510 @ 0x00170510
namespace hulkfight { namespace motion {
struct Track {
    Track();
    virtual void FUN_00236d40_virtual();
    char pad[4];
    int state;
    int pointer;
    float value;
    int extra1, extra2, extra3;
};
struct DriftToHulkTrack : Track {
    virtual void FUN_00236d40_virtual();
    DriftToHulkTrack();
};
DriftToHulkTrack::DriftToHulkTrack() : Track() {
    pointer = 0;
    value = -1.0f;
    extra1 = 0;
    extra2 = 0;
    extra3 = 0;
    state = 1;
}
}}

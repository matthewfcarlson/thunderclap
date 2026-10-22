struct CTriggerVolumeManager_1fcc60 {
    char pad[0xcd];
    unsigned char flag;
};
struct ThisWrap_001fcc60 {
    CTriggerVolumeManager_1fcc60* findObj(int);
    void FUN_001fcc60(int id);
};
void ThisWrap_001fcc60::FUN_001fcc60(int id) {
    CTriggerVolumeManager_1fcc60* p = this->findObj(id);
    if (p)
        p->flag = 1;
}
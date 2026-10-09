extern "C" void __stdcall SetCurrentPosition(unsigned int, unsigned int);
struct SoundThing { char pad[0x14]; unsigned int mInfo; };
struct Player {
    char pad0[0x18];
    unsigned int mPos;
    char pad1[4];
    unsigned int mBuffers[16];
    SoundThing* mSound;
};
void FUN_00258ea0(Player* self, unsigned int position) {
    unsigned int count = (self->mSound->mInfo >> 4) & 0x1f;
    unsigned int chunk = position / count;
    if (count > 0) {
        unsigned int* p = self->mBuffers;
        unsigned int n = count;
        do {
            SetCurrentPosition(*(unsigned int*)(*p + 0x7c), chunk);
            p++;
            n--;
        } while (n != 0);
        self->mPos = position;
    } else {
        self->mPos = position;
    }
}

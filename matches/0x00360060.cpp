extern "C" int __cdecl CreateThing(const char*, int);

void FUN_00360060() {
    *(int*)0x4e69a8 = CreateThing("ChannelVolumeFade", 0);
}
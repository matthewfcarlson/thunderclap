extern "C" char DAT_004e69a8[];
extern "C" int __cdecl CreateThing(const char*, int);

void FUN_00360060() {
    *(int*)((int)DAT_004e69a8) = CreateThing("ChannelVolumeFade", 0);
}
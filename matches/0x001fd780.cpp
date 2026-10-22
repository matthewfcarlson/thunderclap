// Same code shape as 0x000238b0 (propagated; names are from that function)
typedef unsigned int U_1fd780;
typedef unsigned __int64 U64_1fd780;
extern U64_1fd780 __cdecl FUN_0027b020(U_1fd780);
struct CTriggerVolumeManager_1fd780 {
    int Second(U64_1fd780);
    int Target(U_1fd780);
};
int CTriggerVolumeManager_1fd780::Target(U_1fd780 param) {
    U64_1fd780 a = FUN_0027b020(param);
    return Second(a);
}
// Same code shape as 0x0010d280 (propagated; names are from that function)
namespace hulkfight { namespace ai {

class HulkActionTrack {
public:
    char pad0[0xc];
    float mValue;

    float vfunc_6();
};

float HulkActionTrack::vfunc_6()
{
    return mValue;
}

}};
class SpriteLoader {
public:
	virtual void vfunc_0();
	virtual void vfunc_1();
	virtual void vfunc_2();
	virtual void vfunc_3();
	virtual void vfunc_4();
	virtual void vfunc_5();
	virtual void vfunc_6();
	virtual bool GetFlag();
	virtual void vfunc_8();
	virtual void vfunc_9();
	char mPad[0x1D];
	bool mFlag;
};

bool SpriteLoader::GetFlag()
{
	return mFlag;
}

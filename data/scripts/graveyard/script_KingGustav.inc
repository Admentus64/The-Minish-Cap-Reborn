@ Graveyard King Gustav
SCRIPT_START script_KingGustav
	BeginBlock
	DoPostScriptAction 0x0008
	Call sub_0807F180
	EndBlock
script_0800D962:
	CheckPlayerInRegion 0x0118, 0x0038, 0x3050
	JumpIfNot script_0800D962
	_0807E864
	Call sub_0807F9A4
	Call sub_0807DF28
	StartPlayerScript script_PlayerAtKingGustav
	WaitForSyncFlagAndClear 0x00000001
	Wait 0x003c
	_0807EB44 0x0004
	DoPostScriptAction 0x0000
	DoPostScriptAction 0x0007
	PlaySound SFX_ELEMENT_FLOAT
	SetEntity0x20 0xffff8000
	MessageNoOverlap 0x1701
	WaitUntilTextboxCloses
	SetSyncFlag 0x00000004
	WaitForSyncFlagAndClear 0x00000002
	MessageNoOverlap 0x1702
	WaitUntilTextboxCloses
	SetEntity0x20 0x00010000
	SetSyncFlag 0x00000004
	WaitForSyncFlagAndClear 0x00000002
	_0807F050 0x006d
	WaitPlayerGetItem
	_0807EB28 0x1703
	WaitUntilTextboxCloses
	Wait 0x003c
	SetLocalFlag 0x0032
	PlaySound SFX_113
	SetIntVariable 0x00000001
	Call sub_0806DA1C
	Call sub_0807DF50
	_0807E878
	DoPostScriptAction 0x0006
SCRIPT_END
	.2byte 0x0000
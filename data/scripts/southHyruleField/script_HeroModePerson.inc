@ Hyrule Townsperson 3
SCRIPT_START script_HeroModePerson
	BeginBlock
	Call sub_08061FE4
	Call Townsperson_MakeInteractable
	DoPostScriptAction 0x000a
	EndBlock
script_explain_hero_mode:
	CheckEntityInteractType
	JumpIfNot script_explain_hero_mode
	SetPlayerIdle
	FacePlayer
	DoPostScriptAction 0x0000
	MessageNoOverlap TEXT_CAFE, 0x5F
	WaitUntilTextboxCloses
    EnablePlayerControl
    Jump script_explain_hero_mode
@ Hyrule Town Kid in the Inn on the 2nd floor
SCRIPT_START script_KidInn
	BeginBlock
	DoPostScriptAction 0x000a
	Call sub_08062A48
	DoPostScriptAction 0x0000
script_0800D5AC:
	EndBlock
	Call sub_08062698
	Call sub_080626AC
	CallWithArg sub_0807F0EC, 0x00000004
	JumpTable script_0800D5CE, script_0800D5D8, script_0800D5E2, script_0800D5EC
script_0800D5CE:
	_0807EE04 0x0038, 0x0098
	Jump script_0800D5F2
script_0800D5D8:
	_0807EE04 0x0058, 0x0098
	Jump script_0800D5F2
script_0800D5E2:
	_0807EE04 0x0038, 0x00c8
	Jump script_0800D5F2
script_0800D5EC:
	_0807EE04 0x0058, 0x00c8
script_0800D5F2:
	EndBlock
	BeginBlock
	Call sub_080626C0
	JumpIf script_0800D5AC
	_0807EE30
	JumpIfNot script_0800D5F2
	Jump script_0800D5AC
	.2byte 0x0000
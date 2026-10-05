CoalscorchQuarry_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CoalscorchQuarry_B2F_OnLoad
	.byte 0

CoalscorchQuarry_B2F_OnLoad:
	call_if_set FLAG_COALSCORCH_BRIDGE_4, CoalscorchQuarry_B2F_EventScript_Bridge4
	setflag FLAG_COALSCORCH_B2_MAGNUS
	end

CoalscorchQuarry_B2F_EventScript_Bridge4::
	setmetatile 15, 40, METATILE_Underground_LeftTop, TRUE
	setmetatile 15, 41, METATILE_Underground_LeftMiddle, FALSE
	setmetatile 15, 42, METATILE_Underground_LeftBottom, TRUE
	setmetatile 16, 40, METATILE_Underground_CenterTop, TRUE
	setmetatile 16, 41, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 16, 42, METATILE_Underground_CenterBottom, TRUE
	setmetatile 17, 40, METATILE_Underground_CenterTop, TRUE
	setmetatile 17, 41, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 17, 42, METATILE_Underground_CenterBottom, TRUE
	setmetatile 18, 40, METATILE_Underground_RightTop, TRUE
	setmetatile 18, 41, METATILE_Underground_RightMiddle, FALSE
	setmetatile 18, 42, METATILE_Underground_RightBottom, TRUE
	return

CoalscorchQuarry_B2F_EventScript_Switch4::
	lockall
	call_if_unset FLAG_COALSCORCH_BRIDGE_4, CoalscorchQuarry_B2F_EventScript_ActivateBridge4
	releaseall
	end

CoalscorchQuarry_B2F_EventScript_ActivateBridge4::
	lockall
	msgbox CoalscorchQuarry_B1F_Text_StepSwitch, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 3  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 15, 40, METATILE_Underground_LeftTop, TRUE
	setmetatile 15, 41, METATILE_Underground_LeftMiddle, FALSE
	setmetatile 15, 42, METATILE_Underground_LeftBottom, TRUE
	setmetatile 16, 40, METATILE_Underground_CenterTop, TRUE
	setmetatile 16, 41, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 16, 42, METATILE_Underground_CenterBottom, TRUE
	setmetatile 17, 40, METATILE_Underground_CenterTop, TRUE
	setmetatile 17, 41, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 17, 42, METATILE_Underground_CenterBottom, TRUE
	setmetatile 18, 40, METATILE_Underground_RightTop, TRUE
	setmetatile 18, 41, METATILE_Underground_RightMiddle, FALSE
	setmetatile 18, 42, METATILE_Underground_RightBottom, TRUE
	fadescreenspeed FADE_TO_BLACK, 2
	special DrawWholeMapView
	lockall
	msgbox CoalscorchQuarry_B1F_Text_BridgePop, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_COALSCORCH_BRIDGE_4
	fadescreenspeed FADE_FROM_BLACK, 2
	releaseall
	end

Speaker_Sitri:
    .string "Sitri$"

CoalscorchQuarry_B2F_EventScript_Sitri::
	trainerbattle_single TRAINER_GRUNT_SITRI, CoalscorchQuarry_B2F_Text_SitriIntro, CoalscorchQuarry_B2F_Text_SitriDefeat
	setspeaker Speaker_Sitri
	msgbox CoalscorchQuarry_B2F_Text_SitriPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Matthew:
    .string "Matthew$"

CoalscorchQuarry_B2F_EventScript_Matthew::
	trainerbattle_single TRAINER_GRUNT_MATTHEW, CoalscorchQuarry_B2F_Text_MatthewIntro, CoalscorchQuarry_B2F_Text_MatthewDefeat
	setspeaker Speaker_Matthew
	msgbox CoalscorchQuarry_B2F_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Laverna:
    .string "Laverna$"

CoalscorchQuarry_B2F_EventScript_LavernaLeftEnter::
	lockall
	applymovement LOCALID_COALSCORCH_LAVERNA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_COALSCORCH_LAVERNA, CoalscorchQuarry_B2F_Movement_LavernaLeft
	waitmovement 0
	setspeaker Speaker_Laverna
	msgbox CoalscorchQuarry_B2F_Text_LavernaEnter, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LAVERNA_COALSCORCH, CoalscorchQuarry_B2F_Text_LavernaDefeat
	setspeaker Speaker_Laverna
	msgbox CoalscorchQuarry_B2F_Text_LavernaLeave, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COALSCORCH_LAVERNA, CoalscorchQuarry_B2F_Movement_LavernaLeaveLeft
	waitmovement 0
	removeobject LOCALID_COALSCORCH_LAVERNA
	clearflag FLAG_COALSCORCH_B2_MAGNUS
	addobject FLAG_COALSCORCH_B2_MAGNUS
	applymovement LOCALID_COALSCORCH_B2_MAGNUS, CoalscorchQuarry_B2F_Movement_MagnusLeft
	waitmovement
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement
	setspeaker Speaker_Magnus
	msgbox CoalscorchQuarry_B2F_Text_Magnus, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COALSCORCH_B2_MAGNUS, CoalscorchQuarry_B2F_Movement_MagnusLeave
	waitmovement
	removeobject LOCALID_COALSCORCH_B2_MAGNUS
	setflag FLAG_COALSCORCH_B2_MAGNUS
	setvar VAR_STORY, 20
	setflag FLAG_COALSCORCH_CLEARED
	clearflag FLAG_MAGNUS_GYM
	releaseall
	end

CoalscorchQuarry_B2F_EventScript_LavernaRightEnter::
	lockall
	applymovement LOCALID_COALSCORCH_LAVERNA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_COALSCORCH_LAVERNA, CoalscorchQuarry_B2F_Movement_LavernaRight
	waitmovement 0
	setspeaker Speaker_Laverna
	msgbox CoalscorchQuarry_B2F_Text_LavernaEnter, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LAVERNA_COALSCORCH, CoalscorchQuarry_B2F_Text_LavernaDefeat
	setspeaker Speaker_Laverna
	msgbox CoalscorchQuarry_B2F_Text_LavernaLeave, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COALSCORCH_LAVERNA, CoalscorchQuarry_B2F_Movement_LavernaLeaveRight
	waitmovement 0
	removeobject LOCALID_COALSCORCH_LAVERNA
	clearflag FLAG_COALSCORCH_B2_MAGNUS
	addobject FLAG_COALSCORCH_B2_MAGNUS
	applymovement LOCALID_COALSCORCH_B2_MAGNUS, CoalscorchQuarry_B2F_Movement_MagnusRight
	waitmovement
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement
	setspeaker Speaker_Magnus
	msgbox CoalscorchQuarry_B2F_Text_Magnus, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COALSCORCH_B2_MAGNUS, CoalscorchQuarry_B2F_Movement_MagnusLeave
	waitmovement
	removeobject LOCALID_COALSCORCH_B2_MAGNUS
	setflag FLAG_COALSCORCH_B2_MAGNUS
	setvar VAR_STORY, 20
	setflag FLAG_COALSCORCH_CLEARED
	clearflag FLAG_MAGNUS_GYM
	setflag FLAG_FELLHAVEN_JAMES
	releaseall
	end

CoalscorchQuarry_B2F_Movement_LavernaLeft:
	walk_left
	walk_down
	walk_down
	step_end

CoalscorchQuarry_B2F_Movement_LavernaRight:
	walk_down
	walk_down
	step_end

CoalscorchQuarry_B2F_Text_LavernaEnter:
.string "So... you're the one who's been\n"
.string "getting in our way, I heard there was\l"
.string "a rat in our midst.\p"
.string "I was expecting it to be that pesky\n"
.string "Gym Leader, not some kid.\p"
.string "You'll certaintly be much easier to\n"
.string "deal with.\p"
.string "I would tell you to stay out of our\n"
.string "way, but you've already done more than\l"
.string "enough to piss me off.\p"
.string "Thankfully we were able to get all of\n"
.string "the mining equipment out before you\l"
.string "could interfere with that.\p"
.string "What do we need it for?\p"
.string "Hah you'll learn about that soon\n"
.string "enough, don't you worry.\l"
.string "All part of the boss's master plan.\p"
.string "Now enough toying around. Just\n"
.string "because you're a kid doesn't mean\l"
.string "I'll show you any mercy!\p"
.string "Prepare to face the full power of a\n"
.string "Chosen Admin!$"

CoalscorchQuarry_B2F_Text_LavernaDefeat:
.string "What...\n"
.string "Hmm maybe I have underestimated you.$"

CoalscorchQuarry_B2F_Text_LavernaLeave:
.string "Well that was unexpected.\n"
.string "Pay it no attention though, that's the\l"
.string "last time you will defeat me.\p"
.string "In any case, I have what I need, so\n"
.string "I'll be going.\p"
.string "I would advise you to not get in our\n"
.string "way again, there are powers at play\l"
.string "far beyond your comprehension.\p"
.string "But enjoy your tiny victory...\n"
.string "For now.$"

CoalscorchQuarry_B2F_Movement_LavernaLeaveLeft:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CoalscorchQuarry_B2F_Movement_LavernaLeaveRight:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CoalscorchQuarry_B2F_Movement_MagnusLeft:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CoalscorchQuarry_B2F_Movement_MagnusRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CoalscorchQuarry_B2F_Movement_MagnusLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CoalscorchQuarry_B2F_Text_Magnus:
.string "You did it {PLAYER}!\n"
.string "You truly are worthy of the\l"
.string "Campfire Badge.\p"
.string "I cannot thank you enough, even\n"
.string "if we couldn't stop the Chosen\l"
.string "from taking the mining equipment,\p"
.string "helping the miners is quite the\n"
.string "silver lining.\p"
.string "If your friends are trying to\n"
.string "find out more about the motives\l"
.string "of the Chosen,\p"
.string "then I suggest you head to Reme\n"
.string "City to help them out.\p"
.string "It's a long journey, but I think\n"
.string "they'll need all the help they\l"
.string "can get agains the Chosen.\p"
.string "I hope we'll meet again, safe\n"
.string "travels on your journey.$"


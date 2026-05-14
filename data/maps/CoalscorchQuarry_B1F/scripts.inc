CoalscorchQuarry_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CoalscorchQuarry_B1F_OnLoad
	.byte 0

CoalscorchQuarry_B1F_OnLoad:
	call_if_set FLAG_COALSCORCH_BRIDGE_1, CoalscorchQuarry_B1F_EventScript_Bridge1
	call_if_set FLAG_COALSCORCH_BRIDGE_2, CoalscorchQuarry_B1F_EventScript_Bridge2
	call_if_set FLAG_COALSCORCH_BRIDGE_3, CoalscorchQuarry_B1F_EventScript_Bridge3
	end

CoalscorchQuarry_B1F_EventScript_Bridge1::
	setmetatile 32, 7, METATILE_Underground_LeftTop, TRUE
	setmetatile 32, 8, METATILE_Underground_LeftMiddle, FALSE
	setmetatile 32, 9, METATILE_Underground_LeftBottom, TRUE
	setmetatile 33, 7, METATILE_Underground_CenterTop, TRUE
	setmetatile 33, 8, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 33, 9, METATILE_Underground_CenterBottom, TRUE
	setmetatile 34, 7, METATILE_Underground_CenterTop, TRUE
	setmetatile 34, 8, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 34, 9, METATILE_Underground_CenterBottom, TRUE
	setmetatile 35, 7, METATILE_Underground_CenterTop, TRUE
	setmetatile 35, 8, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 35, 9, METATILE_Underground_CenterBottom, TRUE
	setmetatile 36, 7, METATILE_Underground_RightTop, TRUE
	setmetatile 36, 8, METATILE_Underground_RightMiddle, FALSE
	setmetatile 36, 9, METATILE_Underground_RightBottom, TRUE
	return

CoalscorchQuarry_B1F_EventScript_Bridge2::
	setmetatile 20, 37, METATILE_Underground_LeftTop, TRUE
	setmetatile 20, 38, METATILE_Underground_LeftMiddle, FALSE
	setmetatile 20, 39, METATILE_Underground_LeftBottom, TRUE
	setmetatile 21, 37, METATILE_Underground_CenterTop, TRUE
	setmetatile 21, 38, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 21, 39, METATILE_Underground_CenterBottom, TRUE
	setmetatile 22, 37, METATILE_Underground_CenterTop, TRUE
	setmetatile 22, 38, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 22, 39, METATILE_Underground_CenterBottom, TRUE
	setmetatile 23, 37, METATILE_Underground_CenterTop, TRUE
	setmetatile 23, 38, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 23, 39, METATILE_Underground_CenterBottom, TRUE
	setmetatile 24, 37, METATILE_Underground_RightTop, TRUE
	setmetatile 24, 38, METATILE_Underground_RightMiddle, FALSE
	setmetatile 24, 39, METATILE_Underground_RightBottom, TRUE
	return

CoalscorchQuarry_B1F_EventScript_Bridge3::
	setmetatile 39, 25, METATILE_Underground_LeftTop, TRUE
	setmetatile 39, 26, METATILE_Underground_LeftMiddle, FALSE
	setmetatile 39, 27, METATILE_Underground_LeftBottom, TRUE
	setmetatile 40, 25, METATILE_Underground_CenterTop, TRUE
	setmetatile 40, 26, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 40, 27, METATILE_Underground_CenterBottom, TRUE
	setmetatile 41, 25, METATILE_Underground_CenterTop, TRUE
	setmetatile 41, 26, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 41, 27, METATILE_Underground_CenterBottom, TRUE
	setmetatile 42, 25, METATILE_Underground_CenterTop, TRUE
	setmetatile 42, 26, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 42, 27, METATILE_Underground_CenterBottom, TRUE
	setmetatile 43, 25, METATILE_Underground_RightTop, TRUE
	setmetatile 43, 26, METATILE_Underground_RightMiddle, FALSE
	setmetatile 43, 27, METATILE_Underground_RightBottom, TRUE
	return

CoalscorchQuarry_B1F_EventScript_Switch1::
	lockall
	call_if_unset FLAG_COALSCORCH_BRIDGE_1, CoalscorchQuarry_B1F_EventScript_ActivateBridge1
	releaseall
	end

CoalscorchQuarry_B1F_EventScript_ActivateBridge1::
	lockall
	msgbox CoalscorchQuarry_B1F_Text_StepSwitch, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 3  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 32, 7, METATILE_Underground_LeftTop, TRUE
	setmetatile 32, 8, METATILE_Underground_LeftMiddle, FALSE
	setmetatile 32, 9, METATILE_Underground_LeftBottom, TRUE
	setmetatile 33, 7, METATILE_Underground_CenterTop, TRUE
	setmetatile 33, 8, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 33, 9, METATILE_Underground_CenterBottom, TRUE
	setmetatile 34, 7, METATILE_Underground_CenterTop, TRUE
	setmetatile 34, 8, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 34, 9, METATILE_Underground_CenterBottom, TRUE
	setmetatile 35, 7, METATILE_Underground_CenterTop, TRUE
	setmetatile 35, 8, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 35, 9, METATILE_Underground_CenterBottom, TRUE
	setmetatile 36, 7, METATILE_Underground_RightTop, TRUE
	setmetatile 36, 8, METATILE_Underground_RightMiddle, FALSE
	setmetatile 36, 9, METATILE_Underground_RightBottom, TRUE
	fadescreenspeed FADE_TO_BLACK, 2
	special DrawWholeMapView
	lockall
	msgbox CoalscorchQuarry_B1F_Text_BridgePop, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_COALSCORCH_BRIDGE_1
	fadescreenspeed FADE_FROM_BLACK, 2
	releaseall
	end

CoalscorchQuarry_B1F_EventScript_Switch2::
	lockall
	call_if_unset FLAG_COALSCORCH_BRIDGE_2, CoalscorchQuarry_B1F_EventScript_ActivateBridge2
	releaseall
	end

CoalscorchQuarry_B1F_EventScript_ActivateBridge2::
	lockall
	msgbox CoalscorchQuarry_B1F_Text_StepSwitch, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 3  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 20, 37, METATILE_Underground_LeftTop, TRUE
	setmetatile 20, 38, METATILE_Underground_LeftMiddle, FALSE
	setmetatile 20, 39, METATILE_Underground_LeftBottom, TRUE
	setmetatile 21, 37, METATILE_Underground_CenterTop, TRUE
	setmetatile 21, 38, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 21, 39, METATILE_Underground_CenterBottom, TRUE
	setmetatile 22, 37, METATILE_Underground_CenterTop, TRUE
	setmetatile 22, 38, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 22, 39, METATILE_Underground_CenterBottom, TRUE
	setmetatile 23, 37, METATILE_Underground_CenterTop, TRUE
	setmetatile 23, 38, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 23, 39, METATILE_Underground_CenterBottom, TRUE
	setmetatile 24, 37, METATILE_Underground_RightTop, TRUE
	setmetatile 24, 38, METATILE_Underground_RightMiddle, FALSE
	setmetatile 24, 39, METATILE_Underground_RightBottom, TRUE
	fadescreenspeed FADE_TO_BLACK, 2
	special DrawWholeMapView
	lockall
	msgbox CoalscorchQuarry_B1F_Text_BridgePop, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_COALSCORCH_BRIDGE_2
	fadescreenspeed FADE_FROM_BLACK, 2
	releaseall
	end

CoalscorchQuarry_B1F_EventScript_Switch3::
	lockall
	call_if_unset FLAG_COALSCORCH_BRIDGE_3, CoalscorchQuarry_B1F_EventScript_ActivateBridge3
	releaseall
	end

CoalscorchQuarry_B1F_EventScript_ActivateBridge3::
	lockall
	msgbox CoalscorchQuarry_B1F_Text_StepSwitch, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 3  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 39, 25, METATILE_Underground_LeftTop, TRUE
	setmetatile 39, 26, METATILE_Underground_LeftMiddle, FALSE
	setmetatile 39, 27, METATILE_Underground_LeftBottom, TRUE
	setmetatile 40, 25, METATILE_Underground_CenterTop, TRUE
	setmetatile 40, 26, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 40, 27, METATILE_Underground_CenterBottom, TRUE
	setmetatile 41, 25, METATILE_Underground_CenterTop, TRUE
	setmetatile 41, 26, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 41, 27, METATILE_Underground_CenterBottom, TRUE
	setmetatile 42, 25, METATILE_Underground_CenterTop, TRUE
	setmetatile 42, 26, METATILE_Underground_CenterMiddle, FALSE
	setmetatile 42, 27, METATILE_Underground_CenterBottom, TRUE
	setmetatile 43, 25, METATILE_Underground_RightTop, TRUE
	setmetatile 43, 26, METATILE_Underground_RightMiddle, FALSE
	setmetatile 43, 27, METATILE_Underground_RightBottom, TRUE
	fadescreenspeed FADE_TO_BLACK, 2
	special DrawWholeMapView
	lockall
	msgbox CoalscorchQuarry_B1F_Text_BridgePop, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_COALSCORCH_BRIDGE_3
	fadescreenspeed FADE_FROM_BLACK, 2
	releaseall
	end

CoalscorchQuarry_B1F_Text_StepSwitch:
	.string "{PLAYER} stepped on the switch.$"

CoalscorchQuarry_B1F_Text_BridgePop:
	.string "A bridge rose from the lava!$"

Speaker_Mullin:
    .string "Mullin$"

CoalscorchQuarry_B1F_EventScript_Mullin::
	trainerbattle_single TRAINER_GRUNT_MULLIN, CoalscorchQuarry_B1F_Text_MullinIntro, CoalscorchQuarry_B1F_Text_MullinDefeat
	setspeaker Speaker_Mullin
	msgbox CoalscorchQuarry_B1F_Text_MullinPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Nicon:
    .string "Nicon$"

CoalscorchQuarry_B1F_EventScript_Nicon::
	trainerbattle_single TRAINER_GRUNT_NICON, CoalscorchQuarry_B1F_Text_NiconIntro, CoalscorchQuarry_B1F_Text_NiconDefeat
	setspeaker Speaker_Nicon
	msgbox CoalscorchQuarry_B1F_Text_NiconPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Mary:
    .string "Mary$"

CoalscorchQuarry_B1F_EventScript_Mary::
	trainerbattle_single TRAINER_GRUNT_MARY, CoalscorchQuarry_B1F_Text_MaryIntro, CoalscorchQuarry_B1F_Text_MaryDefeat
	setspeaker Speaker_Mary
	msgbox CoalscorchQuarry_B1F_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end






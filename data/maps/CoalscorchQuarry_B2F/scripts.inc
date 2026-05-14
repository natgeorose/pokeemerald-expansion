CoalscorchQuarry_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CoalscorchQuarry_B2F_OnLoad
	.byte 0

CoalscorchQuarry_B2F_OnLoad:
	call_if_set FLAG_COALSCORCH_BRIDGE_4, CoalscorchQuarry_B2F_EventScript_Bridge4
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




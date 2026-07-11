CairwindTown_Player_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CairwindTown_Player_2F_OnFrame
	.byte 0

CairwindTown_Player_2F_OnFrame:
	map_script_2 VAR_STORY, 0, CairwindTown_Player_2F_EventScript_IntroSets
	.2byte 0

CairwindTown_Player_2F_EventScript_IntroSets::
	setflag FLAG_SYS_B_DASH
	setflag FLAG_UNUSED_0x055
	setvar VAR_LEVEL_CAP, 14
	setvar VAR_STORY, 1
	end

CairwindTown_Player_2F_EventScript_PC::
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

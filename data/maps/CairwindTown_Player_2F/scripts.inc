CairwindTown_Player_2F_MapScripts::
	.byte 0

CairwindTown_Player_2F_EventScript_PC::
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

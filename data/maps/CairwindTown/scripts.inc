CairwindTown_MapScripts::
	.byte 0

CairwindTown_EventScript_TownSign::
	msgbox CairwindTown_Text_TownSign, MSGBOX_SIGN
	end

CairwindTown_Text_TownSign:
	.string "Cairwind Town\n"
	.string "“Where the winds of adventure blow.”$"

CairwindTown_EventScript_PlayerHouseSign::
	msgbox CairwindTown_Text_PlayerHouseSign, MSGBOX_SIGN
	end

CairwindTown_Text_PlayerHouseSign:
	.string "“{PLAYER}'s House”$"

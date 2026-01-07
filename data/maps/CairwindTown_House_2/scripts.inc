CairwindTown_House_2_MapScripts::
	.byte 0

Speaker_Scientist:
	.string "Scientist$"

CairwindTown_House2_EventScript_Maniac::
	lockall
	setspeaker Speaker_Scientist
	msgbox CairwindTown_House2_Text_Maniac, MSGBOX_NPC
	releaseall
	end

CairwindTown_House2_Text_Maniac:
	.string "I moved here to study the\n"
	.string "environment around Cairwind Town.\p"
	.string "Between the mountains, river, and\n"
	.string "caves on Route 7, and meadow on\p"
	.string "Route 1, there are so many\n"
	.string "different habitats to explore!$"

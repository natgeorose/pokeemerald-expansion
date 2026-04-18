CairwindTown_House_1_MapScripts::
	.byte 0

CairwindTown_House1_EventScript_ExpertM::
	lockall
	setspeaker Speaker_Elder
	msgbox CairwindTown_House1_Text_ExpertM, MSGBOX_NPC
	releaseall
	end

CairwindTown_House1_Text_ExpertM:
	.string "I have lived in Cairwind Town my\n"
	.string "entire life.\p"
	.string "Thankfully it is still calm here,\n"
	.string "even after so many people moved\l"
	.string "from the Hoenn region.$"

CairwindTown_House1_EventScript_ExpertF::
	lockall
	setspeaker Speaker_Elder
	msgbox CairwindTown_House1_Text_ExpertF, MSGBOX_NPC
	releaseall
	end

CairwindTown_House1_Text_ExpertF:
	.string "It was only a few years ago that\n"
	.string "the legendary Pokémon known as\l"
	.string "Groudon and Kyogre battled,\p"
	.string "causing great damage to the\n"
	.string "environment of the Hoenn region.$"

QuilspringTown_House_1_MapScripts::
	.byte 0

QuilspringTown_House_1_EventScript_Scientist::
	lockall
	setspeaker Speaker_Scientist
	msgbox QuilspringTown_House_1_Text_Scientist, MSGBOX_NPC
	releaseall
	end

QuilspringTown_House_1_Text_Scientist:
	.string "I conduct research with Professor\n"
	.string "Pine. For someone so dedicated to his\p"
	.string "research, he's actually quite easygoing.$"

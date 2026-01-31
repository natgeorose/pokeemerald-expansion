QuilspringTown_House_2_MapScripts::
	.byte 0

QuilspringTown_House_2_EventScript_Woman::
	lockall
	setspeaker Speaker_Woman
	msgbox QuilspringTown_House_2_Text_Woman, MSGBOX_NPC
	releaseall
	end

QuilspringTown_House_2_Text_Woman:
	.string "Life in Quilspring Town revolves around\n"
	.string "the University. Even the Gym Leader, Nyx,\l"
	.string "was a top student at the University.$"

QuilspringTown_House_2_EventScript_Boy::
	lockall
	setspeaker Speaker_Boy
	msgbox QuilspringTown_House_2_Text_Boy, MSGBOX_NPC
	releaseall
	end

QuilspringTown_House_2_Text_Boy:
	.string "My daddy works at the University!$"

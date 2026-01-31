QuilspringTown_House_3_MapScripts::
	.byte 0

QuilspringTown_House_3_EventScript_Woman::
	lockall
	setspeaker Speaker_Woman
	msgbox QuilspringTown_House_3_Text_Woman, MSGBOX_NPC
	releaseall
	end

QuilspringTown_House_3_Text_Woman:
	.string "Have you been to the Milk Bar yet?\p"
	.string "It's the only place you can get Moomoo\n"
	.string "Milk this side of the mountains.$"


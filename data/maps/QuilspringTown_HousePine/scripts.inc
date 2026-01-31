QuilspringTown_HousePine_MapScripts::
	.byte 0

Speaker_Virginia:
    .string "Virginia$"

QuilspringTown_HousePine_EventScript_Virginia::
	lockall
	setspeaker Speaker_Virginia
	msgbox QuilspringTown_HousePine_Text_Virginia, MSGBOX_NPC
	releaseall
	end

QuilspringTown_HousePine_Text_Virginia:
	.string "Hello there! I'm Virginia, Professor\n"
	.string "Pine's wife. Between teaching students\l"
	.string "and his own research, he is quite busy.$"

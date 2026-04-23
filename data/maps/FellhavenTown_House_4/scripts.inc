FellhavenTown_House_4_MapScripts::
	.byte 0

FellhavenTown_House_4_EventScript_Man::
	lockall
	setspeaker Speaker_Elder
	msgbox FellhavenTown_House_4_Text_Man, MSGBOX_NPC
	releaseall
	end

FellhavenTown_House_4_Text_Man:
	.string "The Pokémon Rangers of Serenado are\n"
	.string "the protectors of people, Pokémon,\l"
	.string "and the environment.\p"
	.string "They are highly revered.$"

FellhavenTown_House_4_EventScript_Woman::
	lockall
	setspeaker Speaker_Elder
	msgbox FellhavenTown_House_4_Text_Woman, MSGBOX_NPC
	releaseall
	end

FellhavenTown_House_4_Text_Woman:
	.string "Magnus, the Gym Leader of Sundara\n"
	.string "Village, used to be the head of the\l"
	.string "Pokémon Rangers.\p"
	.string "He traded the mountain chill for\n"
	.string "scorching heat. Hmm I wonder which\l"
	.string "he prefers.$"


FellhavenTown_House_1_MapScripts::
	.byte 0

FellhavenTown_House_1_EventScript_Boy::
	lockall
	setspeaker Speaker_Boy
	msgbox FellhavenTown_House_1_Text_Boy, MSGBOX_NPC
	releaseall
	end

FellhavenTown_House_1_Text_Boy:
	.string "Woah you have Pokémon?\n"
	.string "You must be so cool!$"

FellhavenTown_House_1_EventScript_Woman::
	lockall
	setspeaker Speaker_Woman
	msgbox FellhavenTown_House_1_Text_Woman, MSGBOX_NPC
	releaseall
	end

FellhavenTown_House_1_Text_Woman:
	.string "My son recently became obsessed\n"
	.string "with Pokémon.\p"
	.string "I know it's only a matter of time\n"
	.string "before he sets off on his own.$"



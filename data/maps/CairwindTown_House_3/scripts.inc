CairwindTown_House_3_MapScripts::
	.byte 0

Speaker_Woman:
	.string "Woman$"

CairwindTown_House3_EventScript_Woman::
	lockall
	setspeaker Speaker_Woman
	msgbox CairwindTown_House3_Text_Woman, MSGBOX_NPC
	releaseall
	end

CairwindTown_House3_Text_Woman:
	.string "Cairwind Town is a great place to\n"
	.string "raise a family.\p"
	.string "I know my little one loves it here.$"

CairwindTown_House3_EventScript_Boy::
	lockall
	setspeaker Speaker_Boy
	msgbox CairwindTown_House3_Text_Boy, MSGBOX_NPC
	releaseall
	end

CairwindTown_House3_Text_Boy:
	.string "I hope mommy gives me a Pokémon\n"
	.string "soon,\p"
	.string "I want to battle like my sister!$"

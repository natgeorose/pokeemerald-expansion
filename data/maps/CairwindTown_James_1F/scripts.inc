CairwindTown_James_1F_MapScripts::
	.byte 0

Speaker_JamesDad:
    .string "James' Dad$"

Speaker_Gurdurr:
    .string "Gurdurr$"

CairwindTown_James_1F_EventScript_JamesDad::
	lockall
	setspeaker Speaker_JamesDad
	msgbox CairwindTown_James_1F_Text_JamesDad, MSGBOX_NPC
	releaseall
	end

CairwindTown_James_1F_Text_JamesDad:
	.string "Sigh…\p"
	.string "James is too headstrong, as much as\n"
	.string "he wants to battle he needs to learn\p"
	.string "to use his Pokémon to work and help\n"
	.string "support our family.$"

CairwindTown_James_1F_EventScript_Gurdurr::
	lockall
	playmoncry SPECIES_GURDURR, CRY_MODE_NORMAL
	setspeaker Speaker_Gurdurr
	msgbox CairwindTown_James_1F_Text_Gurdurr, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	releaseall
	end

CairwindTown_James_1F_Text_Gurdurr:
	.string "Grrrrr.$"

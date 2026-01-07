CairwindTown_Isabel_1F_MapScripts::
	.byte 0

Speaker_IsabelMom:
    .string "Isabel's Mom$"

Speaker_IsabelDad:
    .string "Isabel's Dad$"

CairwindTown_Isabel_1F_EventScript_IsabelDad::
	lockall
	setspeaker Speaker_IsabelDad
	msgbox CairwindTown_Isabel_1F_Text_IsabelDad, MSGBOX_NPC
	releaseall
	end

CairwindTown_Isabel_1F_Text_IsabelDad:
	.string "As much as I love that Isabel wants\n"
	.string "to become a researcher,\p"
	.string "I do wish she would get outside\n"
	.string "occasionally.$"

CairwindTown_Isabel_1F_EventScript_IsabelMom::
	lockall
	setspeaker Speaker_IsabelMom
	msgbox CairwindTown_Isabel_1F_Text_IsabelMom, MSGBOX_NPC
	releaseall
	end

CairwindTown_Isabel_1F_Text_IsabelMom:
	.string "Our Isabel is always lost in her\n"
	.string "books, she has always been interested\p"
	.string "in the ancient writings and culture\n"
	.string "of this land.$"

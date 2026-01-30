MoordenVillageHouse_1_MapScripts::
	.byte 0

Speaker_Man:
    .string "Man$"

MoordenVillageHouse_1_EventScript_Man::
	lockall
	setspeaker Speaker_Man
	msgbox MoordenVillageHouse_1_Text_Man, MSGBOX_NPC
	releaseall
	end

MoordenVillageHouse_1_Text_Man:
	.string "Traveling is wonderful, but exhausting.\n"
	.string "As much as I like to see the world, it's\l"
	.string "nice to have a quiet home to return to.$"

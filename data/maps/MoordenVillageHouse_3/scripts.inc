MoordenVillageHouse_3_MapScripts::
	.byte 0

Speaker_Mayor:
    .string "Mayor$"

MoordenVillageHouse_3_EventScript_Mayor::
	lockall
	setspeaker Speaker_Mayor
	msgbox MoordenVillageHouse_3_Text_Mayor, MSGBOX_NPC
	releaseall
	end

MoordenVillageHouse_3_Text_Mayor:
	.string "Ah hello there, welcome to Moorden\n"
	.string "Village! I am the Mayor of this quaint,\l"
	.string "peaceful village.\p"
	.string "I hope you find your time here enjoyable!$"

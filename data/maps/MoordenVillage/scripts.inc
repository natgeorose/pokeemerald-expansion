MoordenVillage_MapScripts::
	.byte 0

MoordenVillage_EventScript_Girl::
	lockall
	setspeaker Speaker_Girl
	msgbox MoordenVillage_Text_Girl, MSGBOX_NPC
	releaseall
	end

MoordenVillage_Text_Girl:
	.string "I love playing in the puddles!$"

Speaker_Ace:
    .string "Ace Trainer$"

MoordenVillage_EventScript_Ace::
	lockall
	setspeaker Speaker_Ace
	msgbox MoordenVillage_Text_Ace, MSGBOX_NPC
	releaseall
	end

MoordenVillage_Text_Ace:
	.string "On the other side of the river here\n"
	.string "lies the deep rainforest of Route 2.\p"
	.string "It's an incredible dangerous place,\n"
	.string "you better be well prepared if you\l"
	.string "are planning on traversing the route.$"

MoordenVillage_EventScript_Boy::
	lockall
	setspeaker Speaker_Boy
	msgbox MoordenVillage_Text_Boy, MSGBOX_NPC
	releaseall
	end

MoordenVillage_Text_Boy:
	.string "This area is so cool, there are so\n"
	.string "many more Water Pokémon than in\l"
	.string "the rest of Serenado.$"

MoordenVillage_EventScript_Elder::
	lockall
	setspeaker Speaker_Elder
	msgbox MoordenVillage_Text_Elder, MSGBOX_NPC
	releaseall
	end

MoordenVillage_Text_Elder:
	.string "This bell was built as a symbol\n"
	.string "of peace, and of the violence that\p"
	.string "was avoided between the natives\n"
	.string "and those immigrating to Serenado.\p"
	.string "Me? I've been in this area for a\n"
	.string "very long time now. But I always\l"
	.string "welcomed those fearing disaster.$"


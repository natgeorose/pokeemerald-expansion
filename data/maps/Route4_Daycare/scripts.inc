Route4_Daycare_MapScripts::
	.byte 0

Route4_PokemonDayCare_EventScript_Man::
	lockall
	faceplayer
	switch VAR_EGG_QUEST
	case 0, Route4_PokemonDayCare_EventScript_ManIntro
	case 1, Route4_PokemonDayCare_EventScript_ManPlease
	end

Route4_PokemonDayCare_EventScript_ManIntro::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_ManIntro, MSGBOX_NPC
	closemessage
	setvar VAR_EGG_QUEST, 1
	releaseall
	end

Route4_PokemonDayCare_Text_ManIntro:
	.string "Y-you there! You're a Trainer, right?\n"
	.string "You have to help me!\p"
	.string "I'm a junior caretaker here at the\n"
	.string "Daycare, and recently I was given\p"
	.string "the task of bringing some Pokémon\n"
	.string "eggs to the Daycare to hatch.\p"
	.string "But my way back I was attacked,\n"
	.string "and the Pokémon eggs were stolen!\p"
	.string "I can't let all of those Trainers\n"
	.string "lose their precious eggs, and I\l"
	.string "definitely can't tell my bosses!\p"
	.string "The thief ran into Erewood Grove,\n"
	.string "but I'm not a Trainer, so I couldn't\l"
	.string "follow him.\p"
	.string "Please help me! Catch the thief and\n"
	.string "bring back the Pokémon eggs!\l"
	.string "I can't lose this job...$"

Route4_PokemonDayCare_EventScript_ManPlease::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_ManPlease, MSGBOX_NPC
	closemessage
	releaseall
	end

Route4_PokemonDayCare_Text_ManPlease:
	.string "Please help me! The thief is\n"
	.string "somewhere in Erewood Grove!$"


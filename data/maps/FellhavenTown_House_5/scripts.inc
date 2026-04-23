FellhavenTown_House_5_MapScripts::
	.byte 0

FellhavenTown_House_5_EventScript_Boy::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_ROAR, FellhavenTown_House_5_EventScript_BoyPost
	setspeaker Speaker_Boy
	msgbox FellhavenTown_House_5_Text_Boy, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_ROAR
	setspeaker Speaker_Boy
	msgbox FellhavenTown_House_5_Text_BoyPost, MSGBOX_NPC
	closemessage
	setflag FLAG_RECEIVED_TM_ROAR
	releaseall
	end

FellhavenTown_House_5_EventScript_BoyPost::
	setspeaker Speaker_Boy
	msgbox FellhavenTown_House_5_Text_BoyPost, MSGBOX_NPC
	closemessage
	releaseall
	end

FellhavenTown_House_5_Text_Boy:
	.string "ROARRRR!\n"
	.string "ROARRRR!\l"
	.string "ROARRRRRRRR!\p"
	.string "I love roaring like a Pokémon!\n"
	.string "Huh, your Pokémon want to learn to\l"
	.string "roar as well?\p"
	.string "Then you should try this!$"

FellhavenTown_House_5_Text_BoyPost:
	.string "ROARRRR!$"

FellhavenTown_House_5_EventScript_Woman::
	lockall
	setspeaker Speaker_Elder
	msgbox FellhavenTown_House_5_Text_Woman, MSGBOX_NPC
	releaseall
	end

FellhavenTown_House_5_Text_Woman:
	.string "I love my grandson, but he's been\n"
	.string "very loud recently...$"





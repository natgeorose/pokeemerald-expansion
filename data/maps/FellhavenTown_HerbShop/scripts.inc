FellhavenTown_HerbShop_MapScripts::
	.byte 0

FellhavenTown_HerbShop_EventScript_Clerk::
	lockall
	faceplayer
	setspeaker Speaker_Clerk
	msgbox FellhavenTown_HerbShop_Text_WhatWouldYouLike, MSGBOX_DEFAULT
	waitmessage
	pokemart FellhavenTown_HerbShop_Pokemart
	setspeaker Speaker_Clerk
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

	.align 2
FellhavenTown_HerbShop_Pokemart:
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_REVIVAL_HERB
	pokemartlistend

FellhavenTown_HerbShop_EventScript_WailmerPailGirl::
	lockall
	faceplayer
	goto_if_unset FLAG_RECEIVED_WAILMER_PAIL, FellhavenTown_HerbShop_EventScript_GiveWailmerPail
	setspeaker Speaker_Clerk
	msgbox FellhavenTown_HerbShop_Text_WailmerPailExplanation, MSGBOX_NPC
	releaseall
	end

FellhavenTown_HerbShop_Text_WailmerPailExplanation:
	.string "While berry plants are growing,\n"
	.string "water them with the Wailmer Pail.$"

FellhavenTown_HerbShop_EventScript_GiveWailmerPail::
	setspeaker Speaker_Clerk
	msgbox FellhavenTown_HerbShop_Text_YouCanHaveThis, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_WAILMER_PAIL
	msgbox FellhavenTown_HerbShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_WAILMER_PAIL
	releaseall
	end

FellhavenTown_HerbShop_Text_YouCanHaveThis:
	.string "Oh hello! I work here at the Herbal\n"
	.string "Medicine Shop.\p"
	.string "I help tend to the herbs and plants\n"
	.string "that we use to make medicience, it is\l"
	.string "a lot of work but it's always worth it.\p"
	.string "You'll like tending to them as well,\n"
	.string "I'm sure of it! You can have this.$"

FellhavenTown_HerbShop_EventScript_Girl::
	lockall
	setspeaker Speaker_Girl
	msgbox FellhavenTown_HerbShop_Text_Girl, MSGBOX_NPC
	releaseall
	end

FellhavenTown_HerbShop_Text_Girl:
	.string "I like spending time here, it always\n"
	.string "smells nice because of the plants.$"

FellhavenTown_HerbShop_Text_WhatWouldYouLike::
	.string "What would you like?$"

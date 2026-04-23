FellhavenTown_PC_MapScripts::
	.byte 0

FellhavenTown_PC_EventScript_Nurse::
	lockall
	setvar VAR_0x800B, LOCALID_FELLHAVEN_NURSE
	call Common_EventScript_SerenadoNurse
	releaseall
	end

FellhavenTown_PC_EventScript_Girl::
	lockall
	setspeaker Speaker_Girl
	msgbox FellhavenTown_PC_Text_Girl, MSGBOX_NPC
	releaseall
	end

FellhavenTown_PC_Text_Girl:
	.string "These Pokémon Centers are so nice,\n"
	.string "they keep my Pokémon nice and healthy!$"

FellhavenTown_PC_EventScript_Boy::
	lockall
	setspeaker Speaker_Boy
	msgbox FellhavenTown_PC_Text_Boy, MSGBOX_NPC
	releaseall
	end

FellhavenTown_PC_Text_Boy:
	.string "The weather in Fellhaven Town is nice,\n"
	.string "but the further you get into the\l"
	.string "mountains, the colder it gets.$"

FellhavenTown_PC_EventScript_Clerk::
	lockall
	faceplayer
	setspeaker Speaker_Clerk
	message gText_HowMayIServeYou
	waitmessage
	pokemart FellhavenTown_PC_Pokemart
	setspeaker Speaker_Clerk
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

	.align 2
FellhavenTown_PC_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_MOON_BALL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_LURE
	pokemartlistend



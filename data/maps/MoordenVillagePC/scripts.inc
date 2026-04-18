MoordenVillagePC_MapScripts::
	.byte 0

MoordenVillage_PC_EventScript_Nurse::
	lockall
	setvar VAR_0x800B, LOCALID_MOORDEN_NURSE
	call Common_EventScript_SerenadoNurse
	releaseall
	end

MoordenVillage_PC_EventScript_Clerk::
	lockall
	faceplayer
	setspeaker Speaker_Clerk
	message gText_HowMayIServeYou
	waitmessage
	pokemart MoordenVillage_PC_Pokemart
	setspeaker Speaker_Clerk
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

	.align 2
MoordenVillage_PC_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_LURE
	pokemartlistend

MoordenVillage_PC_EventScript_Boy::
	lockall
	setspeaker Speaker_Boy
	msgbox MoordenVillage_PC_Text_Boy, MSGBOX_NPC
	releaseall
	end

MoordenVillage_PC_Text_Boy:
	.string "Did you know that different Pokémon\n"
	.string "Centers sell different items?\p"
	.string "Make sure to check them all out!$"

MoordenVillage_PC_EventScript_Man::
	lockall
	setspeaker Speaker_Man
	msgbox MoordenVillage_PC_Text_Man, MSGBOX_NPC
	releaseall
	end

MoordenVillage_PC_Text_Man:
	.string "I wish I knew how to swim, then\n"
	.string "I could visit Elaru Town.\l"
	.string "I hear the food is quite good there.$"


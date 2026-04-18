QuilspringTown_PC_MapScripts::
	.byte 0

QuilspringTown_PC_EventScript_Nurse::
	lockall
	setvar VAR_0x800B, LOCALID_QUILSPRING_NURSE
	call Common_EventScript_SerenadoNurse
	releaseall
	end

QuilspringTown_PC_EventScript_Girl::
	lockall
	setspeaker Speaker_Girl
	msgbox QuilspringTown_PC_Text_Girl, MSGBOX_NPC
	releaseall
	end

QuilspringTown_PC_Text_Girl:
	.string "I can't wait until I'm older and I can\n"
	.string "go to school at the University!$"

QuilspringTown_PC_EventScript_Clerk::
	lockall
	faceplayer
	setspeaker Speaker_Clerk
	message gText_HowMayIServeYou
	waitmessage
	pokemart QuilspringTown_PC_Pokemart
	setspeaker Speaker_Clerk
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

	.align 2
QuilspringTown_PC_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_LURE
	pokemartlistend

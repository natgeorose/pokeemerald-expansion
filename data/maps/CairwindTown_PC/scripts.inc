CairwindTown_PC_MapScripts::
	.byte 0

CairwindTown_PC_EventScript_Nurse::
	lockall
	setvar VAR_0x800B, LOCALID_CAIRWIND_NURSE
	call Common_EventScript_SerenadoNurse
	releaseall
	end

CairwindTown_PC_EventScript_Boy::
	lockall
	setspeaker Speaker_Boy
	call_if_set FLAG_CAIRWIND_MART, CairwindTown_PC_EventScript_BoyBefore
	msgbox CairwindTown_PC_Text_Boy, MSGBOX_NPC
	releaseall
	end

CairwindTown_PC_EventScript_BoyBefore::
	msgbox CairwindTown_PC_Text_BoyBefore, MSGBOX_NPC
	releaseall
	end

CairwindTown_PC_Text_Boy:
	.string "The shop clerk is finally back!\p"
	.string "Now I can finally stock up on\n"
	.string "some supplies.$"

CairwindTown_PC_Text_BoyBefore:
	.string "Apparently the shop clerk is out\n"
	.string "running an errand.$"

CairwindTown_PC_EventScript_Beauty::
	lockall
	setspeaker Speaker_Woman
	msgbox CairwindTown_PC_Text_Beauty, MSGBOX_NPC
	releaseall
	end

CairwindTown_PC_Text_Beauty:
	.string "Pokémon Centers are fantastic!\p"
	.string "Not only can you heal your Pokémon\n"
	.string "or buy items from the shop clerk,\p"
	.string "but the PC in the corner can be\n"
	.string "used to store Pokémon or items.$"

Speaker_Clerk:
    .string "Clerk$"

CairwindTown_PC_EventScript_Clerk::
	lockall
	faceplayer
	setspeaker Speaker_Clerk
	message gText_HowMayIServeYou
	waitmessage
	pokemart CairwindTown_PC_Pokemart
	setspeaker Speaker_Clerk
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

	.align 2
CairwindTown_PC_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_LURE
	pokemartlistend



SundaraVillage_PC_MapScripts::
	.byte 0

SundaraVillage_PC_EventScript_Nurse::
	lockall
	setvar VAR_0x800B, LOCALID_SUNDARA_NURSE
	call Common_EventScript_SerenadoNurse
	releaseall
	end

SundaraVillage_PC_EventScript_Clerk::
	lockall
	faceplayer
	setspeaker Speaker_Clerk
	message gText_HowMayIServeYou
	waitmessage
	pokemart SundaraVillage_PC_Pokemart
	setspeaker Speaker_Clerk
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

	.align 2
SundaraVillage_PC_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_HEAVY_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_LURE
	.2byte ITEM_SUPER_LURE
	pokemartlistend

SundaraVillage_PC_EventScript_Woman::
	lockall
	setspeaker Speaker_Elder
	msgbox SundaraVillage_PC_Text_Woman, MSGBOX_NPC
	releaseall
	end

SundaraVillage_PC_Text_Woman:
	.string "Sundara Village may be small, but\n"
	.string "Coalscorch Quarry plays an important\l"
	.string "role in Serenado's economy.\p"
	.string "The lava rock found here is very\n"
	.string "durable, it's the perfect base for\l"
	.string "building homes across the region.$"




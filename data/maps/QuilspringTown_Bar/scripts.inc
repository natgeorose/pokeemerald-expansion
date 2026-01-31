QuilspringTown_Bar_MapScripts::
	.byte 0

Speaker_Bartender:
    .string "Bartender$"

Speaker_Owner:
    .string "Owner$"

QuilspringTown_Bar_EventScript_Bartender::
	lockall
	faceplayer
	setspeaker Speaker_Bartender
	message gText_WhatWillItBe
	waitmessage
	pokemart QuilspringTown_Bar_Pokemart
	setspeaker Speaker_Bartender
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

	.align 2
QuilspringTown_Bar_Pokemart:
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_PEWTER_CRUNCHIES
	.2byte ITEM_RAGE_CANDY_BAR
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_SHALOUR_SABLE
	pokemartlistend

QuilspringTown_Bar_EventScript_Boy::
	lockall
	setspeaker Speaker_Boy
	msgbox QuilspringTown_Bar_Text_Boy, MSGBOX_NPC
	releaseall
	end

QuilspringTown_Bar_Text_Boy:
	.string "Ah nothing beats kicking back with\n"
	.string "a cold one after a long day of classes.$"

QuilspringTown_Bar_EventScript_Girl::
	lockall
	setspeaker Speaker_Girl
	msgbox QuilspringTown_Bar_Text_Girl, MSGBOX_NPC
	releaseall
	end

QuilspringTown_Bar_Text_Girl:
	.string "I find that a nice glass of Moomoo Milk\n"
	.string "and a hot Lava Cookie gets me in the\l"
	.string "perfect mood to knock out some studying.$"

QuilspringTown_Bar_EventScript_Elder::
	lockall
	setspeaker Speaker_Owner
	msgbox QuilspringTown_Bar_Text_Elder, MSGBOX_NPC
	releaseall
	end

QuilspringTown_Bar_Text_Elder:
	.string "I've been the owner of this fine\n"
	.string "establishment for many years now!\p"
	.string "You'll find only the highest quality\n"
	.string "of food and drink here, the Moomoo Milk\l"
	.string "comes from only the best cows in Soloam.$"


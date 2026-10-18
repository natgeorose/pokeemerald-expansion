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

MoordenVillage_PC_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_MOORDEN_NPC_TRADE_COMPLETED, MoordenVillage_PC_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_VAROOM
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	setspeaker Speaker_Boy
	msgbox MoordenVillage_PC_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoordenVillage_PC_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MoordenVillage_PC_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, MoordenVillage_PC_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	setspeaker Speaker_Boy
	msgbox MoordenVillage_PC_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_MOORDEN_NPC_TRADE_COMPLETED
	release
	end

MoordenVillage_PC_EventScript_DeclineTrade::
	setspeaker Speaker_Boy
	msgbox MoordenVillage_PC_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

MoordenVillage_PC_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	setspeaker Speaker_Boy
	msgbox MoordenVillage_PC_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

MoordenVillage_PC_EventScript_TradeCompleted::
	setspeaker Speaker_Boy
	msgbox MoordenVillage_PC_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

MoordenVillage_PC_Text_IllTradeIfYouWant:
	.string "Waaahhhhh!\p"
	.string "I told my parents I wanted a Murkrow\n"
	.string "for my birthday, but they gave me this\l"
	.string "Varoom instead!\p"
	.string "Please do you have a Murkrow?\p"
	.string "I'll give you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1}, I need one!$"

MoordenVillage_PC_Text_PleaseBeGoodToMyPokemon:
	.string "Yay thank you!$"

MoordenVillage_PC_Text_DoesntLookLikeMonToMe:
	.string "No I want a Murkrow!$"

MoordenVillage_PC_Text_YouDontWantToThatsOkay:
	.string "Please bring me a Murkrow!$"

MoordenVillage_PC_Text_AnyPokemonCanBeCute:
	.string "I always wanted to have a bird\n"
	.string "Pokémon like Murkrow!$"


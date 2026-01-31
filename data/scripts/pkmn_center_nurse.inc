Common_EventScript_PkmnCenterNurse::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, CountPlayerTrainerStars
	goto_if_eq VAR_RESULT, 4, EventScript_PkmnCenterNurse_GoldCard
	msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_Goodbye::
	message gText_WeHopeToSeeYouAgain
	return

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	call_if_eq VAR_0x8004, 0, EventScript_PkmnCenterNurse_IllTakeYourPkmn
	call_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_IllTakeYourPkmn2
	waitmessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_IllTakeYourPkmn::
	message gText_IllTakeYourPkmn
	return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
	message gText_IllTakeYourPkmn2
	return

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	hidefollower 0
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Turn
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
.if OW_UNION_DISABLE_CHECK == FALSE && OW_FLAG_MOVE_UNION_ROOM_CHECK != 0
	setflag OW_FLAG_MOVE_UNION_ROOM_CHECK
	call CableClub_OnResume
	clearflag OW_FLAG_MOVE_UNION_ROOM_CHECK
.endif
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
	specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
	end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn::
	goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_ReturnPkmn2
	message gText_RestoredPkmnToFullHealth
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_ReturnPkmn2::
	message gText_ThankYouForWaiting
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
	message CableClub_Text_PlayerIsWaiting
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_CheckPokerus::
	specialvar VAR_RESULT, IsPokerusInParty
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
	end

EventScript_PkmnCenterNurse_ExplainPokerus::
	message gText_PokerusExplanation
	setflag FLAG_POKERUS_EXPLAINED
	return

EventScript_PkmnCenterNurse_GoldCard::
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
	setflag FLAG_NURSE_MENTIONS_GOLD_CARD
	msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x800B, Common_Movement_Delay48
	waitmovement 0
	msgbox gText_NoticesGoldCard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_AskForUsual::
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_GoldCardHealPkmn::
	setvar VAR_0x8004, 1
	goto EventScript_PkmnCenterNurse_HealPkmn
	end

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end

Movement_PkmnCenterNurse_Turn:
	walk_in_place_faster_left
	step_end

Speaker_Nurse:
    .string "Nurse$"

Common_EventScript_SerenadoNurse::
	lockall
	faceplayer
	setspeaker Speaker_Nurse
	msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_DEFAULT
	closemessage
	incrementgamestat GAME_STAT_USED_POKECENTER
	hidefollower 0
	applymovement VAR_0x800B, Common_Movement_FaceLeft
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	fadescreenswapbuffers FADE_FROM_BLACK
	applymovement VAR_0x800B, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_Nurse
	msgbox gText_WeHopeToSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Common_PC_EventScript_VendingMachine::
	lockall
	message Common_PC_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto Common_PC_EventScript_ChooseDrink
	end

Common_PC_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, Common_PC_EventScript_FreshWater
	case 1, Common_PC_EventScript_SodaPop
	case 2, Common_PC_EventScript_Lemonade
	msgbox Common_PC_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto Common_PC_EventScript_ExitVendingMachine
	end

Common_PC_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto Common_PC_EventScript_TryBuyDrink
	end

Common_PC_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto Common_PC_EventScript_TryBuyDrink
	end

Common_PC_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto Common_PC_EventScript_TryBuyDrink
	end

Common_PC_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

Common_PC_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

Common_PC_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

Common_PC_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

Common_PC_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

Common_PC_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

Common_PC_EventScript_TryBuyDrink::
	call_if_eq VAR_TEMP_1, 0, Common_PC_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, Common_PC_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, Common_PC_EventScript_CheckMoneyLemonade
	goto_if_eq VAR_RESULT, FALSE, Common_PC_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, Common_PC_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, Common_PC_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, Common_PC_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, Common_PC_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox Common_PC_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, Common_PC_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, Common_PC_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox Common_PC_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
	goto_if_ne VAR_RESULT, 0, Common_PC_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, Common_PC_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox Common_PC_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto Common_PC_EventScript_ChooseNewDrink
	end

Common_PC_EventScript_ChooseNewDrink::
	message Common_PC_Text_WhichDrinkWouldYouLike
	waitmessage
	goto Common_PC_EventScript_ChooseDrink
	end

Common_PC_EventScript_NotEnoughMoneyForDrink::
	msgbox Common_PC_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto Common_PC_EventScript_ExitVendingMachine
	end

Common_PC_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto Common_PC_EventScript_ExitVendingMachine
	end

Common_PC_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

Common_PC_Text_WhichDrinkWouldYouLike:
	.string "It's a vending machine.\n"
	.string "Which drink would you like?$"

Common_PC_Text_CanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

Common_PC_Text_ExtraCanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

Common_PC_Text_NotEnoughMoney:
	.string "Not enough money…$"

Common_PC_Text_DecidedAgainstBuyingDrink:
	.string "Decided against buying a drink.$"


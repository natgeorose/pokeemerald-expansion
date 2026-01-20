Route117_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	waitstate
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	waitstate
	releaseall
	end

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "I'm the Day-Care Man.\p"
	.string "I help take care of the precious\n"
	.string "Pokémon of Trainers.\p"
	.string "If you'd like me to raise your Pokémon,\n"
	.string "have a word with my wife.$"

Route117_Text_DoYouWantEgg:
	.string "Ah, it's you!\p"
	.string "We were raising your Pokémon,\n"
	.string "and my goodness, were we surprised!\p"
	.string "Your Pokémon had an egg!\p"
	.string "We don't know how it got there,\n"
	.string "but your Pokémon had it.\p"
	.string "You do want it, yes?$"

Route117_Text_YourMonIsDoingFine:
	.string "Ah, it's you! Good to see you.\n"
	.string "Your {STR_VAR_1}'s doing fine.$"

Route117_Text_IllKeepIt:
	.string "Well then, I'll keep it.\n"
	.string "Thanks!$"

Route117_Text_YouHaveNoRoomForIt:
	.string "You have no room for it…\n"
	.string "Come back when you've made room.$"

Route117_Text_ReceivedEgg:
	.string "{PLAYER} received the egg from\n"
	.string "the Day-Care Man.$"

Route117_Text_TakeGoodCareOfIt:
	.string "Take good care of it.$"

Route117_Text_FriendlyWithOtherTrainersMon:
	.string "By the way, about your {STR_VAR_1},\n"
	.string "it seemed to be friendly with\l"
	.string "{STR_VAR_2}'s {STR_VAR_3}.\p"
	.string "I may even have seen it receiving\n"
	.string "a piece of Mail.$"

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon:
	.string "If you want to pick up your Pokémon,\n"
	.string "have a word with my wife.$"

Route117_Text_YourMonsAreDoingFine:
	.string "Ah, it's you! Your {STR_VAR_1} and\n"
	.string "{STR_VAR_2} are doing fine.$"

Route117_Text_IWillKeepDoYouWantIt:
	.string "I really will keep it.\n"
	.string "You do want this, yes?$"

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "I'm the Day-Care Lady.\p"
	.string "We can raise Pokémon for you.\p"
	.string "Would you like us to raise one?$"

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string "Which Pokémon should we raise for\n"
	.string "you?$"

Route117_PokemonDayCare_Text_WellRaiseYourMon:
	.string "Fine, we'll raise your {STR_VAR_1}\n"
	.string "for a while.\p"
	.string "Come back for it later.$"

Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string "We can raise two of your Pokémon.\n"
	.string "Would you like us to raise one more?$"

Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
	.string "My husband was looking for you.$"

Route117_PokemonDayCare_Text_FineThenComeAgain:
	.string "Oh, fine, then.\n"
	.string "Come again.$"

Route117_PokemonDayCare_Text_NotEnoughMoney:
	.string "You don't have enough money…$"

Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string "Will you take back the other one,\n"
	.string "too?$"

Route117_PokemonDayCare_Text_ComeAgain:
	.string "Fine.\n"
	.string "Come again.$"

Route117_PokemonDayCare_Text_GoodToSeeYou:
	.string "Ah, it's you! Good to see you.\n"
	.string "Your Pokémon can only be doing good!$"

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string "By level, your {STR_VAR_1} has\n"
	.string "grown by {STR_VAR_2}.$"

Route117_PokemonDayCare_Text_YourTeamIsFull:
	.string "Your Pokémon team is full.\n"
	.string "Make room, then come see me.$"

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon:
	.string "Which Pokémon will you take back?$"

Route117_PokemonDayCare_Text_ItWillCostX:
	.string "If you want your {STR_VAR_1} back,\n"
	.string "it will cost ¥{STR_VAR_2}.$"

Route117_PokemonDayCare_Text_HeresYourMon:
	.string "Perfect!\n"
	.string "Here's your Pokémon.$"

Route117_PokemonDayCare_Text_TookBackMon:
	.string "{PLAYER} took back {STR_VAR_1} from\n"
	.string "the Day-Care Lady.$"

Route117_PokemonDayCare_Text_YouHaveJustOneMon:
	.string "Oh? But you have just one\n"
	.string "Pokémon.\p"
	.string "Come back another time.$"

Route117_PokemonDayCare_Text_TakeYourMonBack:
	.string "Will you take your Pokémon back?$"

Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string "If you leave me that Pokémon,\n"
	.string "what will you battle with?\p"
	.string "Come back another time.$"

Text_EggHatchHuh:
	.string "Huh?$"

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string "Huh?\n"
	.string "Now, now.\p"
	.string "If you leave that Pokémon with\n"
	.string "me, you'll be left with just one.\p"
	.string "You will be better off if you catch\n"
	.string "some more, I dare say.$"

Speaker_Caretaker:
    .string "Caretaker$"

Route4_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route4_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route4_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route4_EventScript_CheckOnTwoMons
	setspeaker Speaker_Caretaker
	msgbox Route4_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route4_EventScript_DaycareEggWaiting::
	setspeaker Speaker_Caretaker
	msgbox Route4_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route4_EventScript_DaycareAcceptEgg
	setspeaker Speaker_Caretaker
	msgbox Route4_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route4_EventScript_DaycareAcceptEgg
	setspeaker Speaker_Caretaker
	msgbox Route4_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route4_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route4_EventScript_DaycareReceiveEgg
	setspeaker Speaker_Caretaker
	msgbox Route4_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	closemessage
	release
	end

Route4_EventScript_DaycareReceiveEgg::
	message Route4_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	setspeaker Speaker_Caretaker
	msgbox Route4_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	closemessage
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route4_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route4_EventScript_MonReceivedMail
	return

Route4_EventScript_MonReceivedMail::
	setspeaker Speaker_Caretaker
	msgbox Route4_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	closemessage
	return

Route4_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	setspeaker Speaker_Caretaker
	msgbox Route4_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route4_EventScript_CheckMonReceivedMail
	release
	end

Route4_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	setspeaker Speaker_Caretaker
	msgbox Route4_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route4_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route4_EventScript_CheckMonReceivedMail
	release
	end

Route4_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route4_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route4_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route4_PokemonDayCare_EventScript_TwoMonsInDaycare
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route4_PokemonDayCare_EventScript_GiveMonToRaise
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route4_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route4_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route4_PokemonDayCare_EventScript_OnlyTwoAliveMons
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route4_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route4_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route4_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route4_PokemonDayCare_EventScript_ComeAgain::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	closemessage
	release
	end

Route4_PokemonDayCare_EventScript_CanRaiseOneMore::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route4_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route4_PokemonDayCare_EventScript_ComeAgain
	end

Route4_PokemonDayCare_EventScript_OnlyOneMon::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route4_PokemonDayCare_EventScript_OnlyOneAliveMon::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	closemessage
	release
	end

Route4_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	closemessage
	release
	end

Route4_PokemonDayCare_EventScript_EggWaiting::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	closemessage
	release
	end

Route4_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	closemessage
	return

Route4_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route4_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route4_PokemonDayCare_EventScript_OneMonInDaycare::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 0
	call Route4_PokemonDayCare_EventScript_DisplayLevelsGained
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route4_PokemonDayCare_EventScript_GiveMonToRaise
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route4_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route4_PokemonDayCare_EventScript_ComeAgain
	end

Route4_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route4_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route4_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route4_PokemonDayCare_EventScript_ComeAgain
	goto Route4_PokemonDayCare_EventScript_CostPrompt
	end

Route4_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCost
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route4_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route4_PokemonDayCare_EventScript_ComeAgain
	end

Route4_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route4_PokemonDayCare_EventScript_RetrieveMon
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	release
	end

Route4_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route4_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route4_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route4_PokemonDayCare_EventScript_ComeAgain
	end

Route4_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route4_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route4_PokemonDayCare_EventScript_ComeAgain
	end

Route4_PokemonDayCare_EventScript_NoRoom::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	closemessage
	release
	end

Route4_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route4_PokemonDayCare_EventScript_UnusedEnd::
	end

Route4_PokemonDayCare_EventScript_TwoMonsInDaycare::
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 0
	call Route4_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route4_PokemonDayCare_EventScript_DisplayLevelsGained
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route4_PokemonDayCare_EventScript_TryRetrieveMon
	setspeaker Speaker_Caretaker
	msgbox Route4_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	closemessage
	release
	end

@ Unused
Route4_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	waitstate
	goto_if_eq VAR_RESULT, 2, Route4_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route4_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route4_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route4_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "I'm the Day-Care Man.\p"
	.string "I help take care of the precious\n"
	.string "Pokémon of Trainers.\p"
	.string "If you'd like me to raise your Pokémon,\n"
	.string "have a word with my wife.$"

Route4_Text_DoYouWantEgg:
	.string "Ah, it's you!\p"
	.string "We were raising your Pokémon,\n"
	.string "and my goodness, were we surprised!\p"
	.string "Your Pokémon had an egg!\p"
	.string "We don't know how it got there,\n"
	.string "but your Pokémon had it.\p"
	.string "You do want it, yes?$"

Route4_Text_YourMonIsDoingFine:
	.string "Ah, it's you! Good to see you.\n"
	.string "Your {STR_VAR_1}'s doing fine.$"

Route4_Text_IllKeepIt:
	.string "Well then, I'll keep it.\n"
	.string "Thanks!$"

Route4_Text_YouHaveNoRoomForIt:
	.string "You have no room for it…\n"
	.string "Come back when you've made room.$"

Route4_Text_ReceivedEgg:
	.string "{PLAYER} received the egg from\n"
	.string "the Day-Care Man.$"

Route4_Text_TakeGoodCareOfIt:
	.string "Take good care of it.$"

Route4_Text_FriendlyWithOtherTrainersMon:
	.string "By the way, about your {STR_VAR_1},\n"
	.string "it seemed to be friendly with\l"
	.string "{STR_VAR_2}'s {STR_VAR_3}.\p"
	.string "I may even have seen it receiving\n"
	.string "a piece of Mail.$"

@ Unused
Route4_Text_SeeWifeIfYouWantToPickUpMon:
	.string "If you want to pick up your Pokémon,\n"
	.string "have a word with my wife.$"

Route4_Text_YourMonsAreDoingFine:
	.string "Ah, it's you! Your {STR_VAR_1} and\n"
	.string "{STR_VAR_2} are doing fine.$"

Route4_Text_IWillKeepDoYouWantIt:
	.string "I really will keep it.\n"
	.string "You do want this, yes?$"

Route4_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "I'm the Day-Care Lady.\p"
	.string "We can raise Pokémon for you.\p"
	.string "Would you like us to raise one?$"

Route4_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string "Which Pokémon should we raise for\n"
	.string "you?$"

Route4_PokemonDayCare_Text_WellRaiseYourMon:
	.string "Fine, we'll raise your {STR_VAR_1}\n"
	.string "for a while.\p"
	.string "Come back for it later.$"

Route4_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string "We can raise two of your Pokémon.\n"
	.string "Would you like us to raise one more?$"

Route4_PokemonDayCare_Text_HusbandWasLookingForYou:
	.string "My husband was looking for you.$"

Route4_PokemonDayCare_Text_FineThenComeAgain:
	.string "Oh, fine, then.\n"
	.string "Come again.$"

Route4_PokemonDayCare_Text_NotEnoughMoney:
	.string "You don't have enough money…$"

Route4_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string "Will you take back the other one,\n"
	.string "too?$"

Route4_PokemonDayCare_Text_ComeAgain:
	.string "Fine.\n"
	.string "Come again.$"

Route4_PokemonDayCare_Text_GoodToSeeYou:
	.string "Ah, it's you! Good to see you.\n"
	.string "Your Pokémon can only be doing good!$"

Route4_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string "By level, your {STR_VAR_1} has\n"
	.string "grown by {STR_VAR_2}.$"

Route4_PokemonDayCare_Text_YourTeamIsFull:
	.string "Your Pokémon team is full.\n"
	.string "Make room, then come see me.$"

@ Unused
Route4_PokemonDayCare_Text_TakeBackWhichMon:
	.string "Which Pokémon will you take back?$"

Route4_PokemonDayCare_Text_ItWillCostX:
	.string "If you want your {STR_VAR_1} back,\n"
	.string "it will cost ¥{STR_VAR_2}.$"

Route4_PokemonDayCare_Text_HeresYourMon:
	.string "Perfect!\n"
	.string "Here's your Pokémon.$"

Route4_PokemonDayCare_Text_TookBackMon:
	.string "{PLAYER} took back {STR_VAR_1} from\n"
	.string "the Day-Care Lady.$"

Route4_PokemonDayCare_Text_YouHaveJustOneMon:
	.string "Oh? But you have just one\n"
	.string "Pokémon.\p"
	.string "Come back another time.$"

Route4_PokemonDayCare_Text_TakeYourMonBack:
	.string "Will you take your Pokémon back?$"

Route4_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string "If you leave me that Pokémon,\n"
	.string "what will you battle with?\p"
	.string "Come back another time.$"

Route4_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string "Huh?\n"
	.string "Now, now.\p"
	.string "If you leave that Pokémon with\n"
	.string "me, you'll be left with just one.\p"
	.string "You will be better off if you catch\n"
	.string "some more, I dare say.$"


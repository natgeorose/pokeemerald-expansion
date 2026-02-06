ErewoodGrove_MapScripts::
	.byte 0

Speaker_Reid:
    .string "Reid$"

ErewoodGrove_EventScript_Reid::
	trainerbattle_single TRAINER_REID, ErewoodGrove_Text_ReidIntro, ErewoodGrove_Text_ReidDefeat
	setspeaker Speaker_Reid
	msgbox ErewoodGrove_Text_ReidPostBattle, MSGBOX_AUTOCLOSE
	end

ErewoodGrove_EventScript_ChooseParty::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, ErewoodGrove_EventScript_StartTag
	special LoadPlayerParty
	goto ErewoodGrove_EventScript_ChooseParty

ErewoodGrove_EventScript_StartTag::
	multi_2_vs_2 TRAINER_NICK_EREWOOD, ErewoodGrove_Text_NickDefeat, TRAINER_NATE_EREWOOD, ErewoodGrove_Text_NateDefeat, PARTNER_JAMES
	switch VAR_RESULT
	case 1, ErewoodGrove_EventScript_DefeatedThem
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

ErewoodGrove_EventScript_DefeatedThem::
	msgbox ErewoodGrove_Text_Victory, MSGBOX_DEFAULT
	releaseall
	end

ErewoodGrove_Text_NickDefeat:
	.string "No.$"

ErewoodGrove_Text_NateDefeat:
	.string "Plz.$"

ErewoodGrove_Text_Victory:
	.string "You win.$"


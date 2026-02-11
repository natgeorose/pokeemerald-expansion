ErewoodGrove_MapScripts::
	.byte 0

Speaker_Reid:
    .string "Reid$"

Speaker_Nick:
    .string "Nick$"

Speaker_Nate:
    .string "Nate$"

ErewoodGrove_EventScript_Reid::
	trainerbattle_single TRAINER_REID, ErewoodGrove_Text_ReidIntro, ErewoodGrove_Text_ReidDefeat
	setspeaker Speaker_Reid
	msgbox ErewoodGrove_Text_ReidPostBattle, MSGBOX_AUTOCLOSE
	end

ErewoodGrove_EventScript_JamesEnter::
	lockall
	clearflag FLAG_HIDE_EREWOOD_NICKNATE
	addobject LOCALID_EREWOOD_NATE
	addobject LOCALID_EREWOOD_NICK
	addobject LOCALID_EREWOOD_JAMES
	setspeaker Speaker_James
	msgbox ErewoodGrove_Text_JamesWaitUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_EREWOOD_JAMES, ErewoodGrove_Movement_JamesInitital
	waitmovement 0
	goto_if_set FLAG_TEMP_11, ErewoodGrove_EventScript_JamesEnterLeft	
	applymovement LOCALID_EREWOOD_JAMES, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_EREWOOD_TREE, Movement_CutTreeDown
	waitmovement 0
	removeobject LOCALID_EREWOOD_TREE
	applymovement LOCALID_EREWOOD_JAMES, Common_Movement_WalkUp2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_EREWOOD_JAMES, Common_Movement_FaceRight
	waitmovement 0
	goto ErewoodGrove_EventScript_JamesGoUp


ErewoodGrove_EventScript_JamesEnterLeft::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 24, ErewoodGrove_EventScript_JamesEnterLeftRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_EREWOOD_JAMES, ErewoodGrove_Movement_JamesEnterLeftLeft
	waitmovement 0
	goto ErewoodGrove_EventScript_JamesGoUp

ErewoodGrove_EventScript_JamesEnterLeftRight::
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_EREWOOD_JAMES, ErewoodGrove_Movement_JamesEnterLeftRight
	waitmovement 0
	goto ErewoodGrove_EventScript_JamesGoUp

ErewoodGrove_EventScript_JamesGoUp::
	setspeaker Speaker_James
	msgbox ErewoodGrove_Text_JamesFinally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_EREWOOD_JAMES, Common_Movement_FaceUp
	waitmovement 0
	setspeaker Speaker_James
	msgbox ErewoodGrove_Text_JamesWoah, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, ErewoodGrove_Movement_WalkUp3
	applymovement LOCALID_EREWOOD_JAMES, ErewoodGrove_Movement_WalkUp3
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
	waitmovement 0
	delay 10
	applymovement LOCALID_EREWOOD_NICK, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setspeaker Speaker_Unknown
	msgbox ErewoodGrove_Text_NickMan, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EREWOOD_NATE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setspeaker Speaker_Unknown
	msgbox ErewoodGrove_Text_NateIKnow, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EREWOOD_NICK, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setspeaker Speaker_Nick
	msgbox ErewoodGrove_Text_NickSheWillNot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EREWOOD_NATE, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	delay 8
	applymovement LOCALID_EREWOOD_NATE, Common_Movement_FaceRight
	waitmovement 0
	setspeaker Speaker_Nate
	msgbox ErewoodGrove_Text_NateCompany, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EREWOOD_NICK, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_EREWOOD_NICK, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker Speaker_Nick
	msgbox ErewoodGrove_Text_NickWhat, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EREWOOD_NICK, Common_Movement_WalkDownFast
	applymovement LOCALID_EREWOOD_NATE, Common_Movement_WalkDown
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
	waitmovement 0
	waitmovement 0
	setspeaker Speaker_Nick
	msgbox ErewoodGrove_Text_NickYouThere, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_James
	msgbox ErewoodGrove_Text_JamesHeard, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Nate
	msgbox ErewoodGrove_Text_NateYeahNo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EREWOOD_NATE, Common_Movement_FaceRight
	waitmovement 0
	setspeaker Speaker_Nate
	msgbox ErewoodGrove_Text_NateCantLet, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EREWOOD_NICK, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker Speaker_Nick
	msgbox ErewoodGrove_Text_NickIKnow, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EREWOOD_NICK, Common_Movement_FaceDown
	applymovement LOCALID_EREWOOD_NATE, Common_Movement_FaceDown
	waitmovement 0
	playbgm MUS_BW12_055, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_EREWOOD_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	setspeaker Speaker_James
	msgbox ErewoodGrove_Text_JamesFight, MSGBOX_DEFAULT
	closemessage
	goto ErewoodGrove_EventScript_ChooseParty

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
	setspeaker Speaker_Nate
	msgbox ErewoodGrove_Text_NateUgh, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_James
	msgbox ErewoodGrove_Text_JamesWon, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Nick
	msgbox ErewoodGrove_Text_NickOneThing, MSGBOX_DEFAULT
	closemessage
	delay 8
	playse SE_PIN
	applymovement LOCALID_EREWOOD_JAMES, Common_Movement_QuestionMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_EREWOOD_NICK, ErewoodGrove_Movement_NickMove1
	applymovement LOCALID_EREWOOD_NATE, ErewoodGrove_Movement_NateMove1
	waitmovement 0 
	applymovement LOCALID_EREWOOD_JAMES, Common_Movement_FaceDown
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_EREWOOD_NICK, ErewoodGrove_Movement_NickMove2
	applymovement LOCALID_EREWOOD_NATE, ErewoodGrove_Movement_NateMove2
	waitmovement 0
	playse SE_UNLOCK
	applymovement LOCALID_EREWOOD_JAMES, ErewoodGrove_Movement_PushedIn
	applymovement LOCALID_PLAYER, ErewoodGrove_Movement_PushedIn
	waitmovement 0
	playse SE_FALL
	hideplayer
	removeobject LOCALID_EREWOOD_JAMES
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
	applymovement LOCALID_EREWOOD_NICK, Common_Movement_WalkUp4
	applymovement LOCALID_EREWOOD_NATE, Common_Movement_WalkUp4
	waitmovement 0
	setspeaker Speaker_Nate
	msgbox ErewoodGrove_Text_NateCantSay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EREWOOD_NATE, Common_Movement_FaceRight
	waitmovement 0
	setspeaker Speaker_Nate
	msgbox ErewoodGrove_Text_NateEscape, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EREWOOD_NICK, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker Speaker_Nick
	msgbox ErewoodGrove_Text_NickUhh, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Nate
	msgbox ErewoodGrove_Text_NateEhh, MSGBOX_DEFAULT
	closemessage
	warpsilent MAP_EREWOOD_GROVE_B1F, 28, 40
	releaseall
	end

ErewoodGrove_Text_JamesWaitUp:
	.string "Hey {PLAYER}, wait up!$"

ErewoodGrove_Movement_JamesInitital:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

ErewoodGrove_Movement_JamesEnterLeftRight:
	walk_up
	walk_right
	walk_up
	face_left
	step_end

ErewoodGrove_Movement_JamesEnterLeftLeft:
	walk_up
	walk_up
	face_right
	step_end

ErewoodGrove_Text_JamesFinally:
	.string "Finally I caught up with you!\p"
	.string "Of course you didn't need me to show\n"
	.string "you how to cut down trees, you really\l"
	.string "are a natural!$"

ErewoodGrove_Text_JamesWoah:
	.string "Woah this place really is creepy,\n"
	.string "let's check it out together!$"

ErewoodGrove_Movement_WalkUp3:
	walk_up
	walk_up
	walk_up
	step_end

ErewoodGrove_Text_NickMan:
	.string "I can't believe we went through that\n"
	.string "entire tree hollow system and we didn't\l"
	.string "find anything!$"

ErewoodGrove_Text_NateIKnow:
	.string "I know Nick, that was not the outcome I\n"
	.string "was looking for...\p"
	.string "The boss will not be pleased to hear that\n"
	.string "our mission was not a success, it seems\l"
	.string "like the search will have to continue.$"

ErewoodGrove_Text_NickSheWillNot:
	.string "No, she will definitely not be happy\n"
	.string "to hear that...\p"
	.string "Well Nate, I guess our mission is over,\n"
	.string "we should really meet up with the rest\l"
	.string "of the Chosen at the quarry.$"

ErewoodGrove_Text_NateCompany:
	.string "Brother, it appears that we have company.$"

ErewoodGrove_Text_NickWhat:
	.string "Huh, what?!$"

ErewoodGrove_Text_NickYouThere:
	.string "You there!! What are you kids doing in\n"
	.string "these woods?!\l"
	.string "How much did you hear?!?$"

ErewoodGrove_Text_JamesHeard:
	.string "W-we heard enough! Who are you guys?$"

ErewoodGrove_Text_NateYeahNo:
	.string "Yeahh we're not going to answer that\n"
	.string "question, that's not for you to know.$"

ErewoodGrove_Text_NateCantLet:
	.string "We can't let them follow us, Nick.$"

ErewoodGrove_Text_NickIKnow:
	.string "I know, we have to eliminate them.$"

ErewoodGrove_Text_JamesFight:
	.string "Woah, what?\n"
	.string "That escalated quickly!\p"
	.string "Well we're not going down without\n"
	.string "a fight!\p"
	.string "{PLAYER}, let's team up and\n"
	.string "take them on!$"

ErewoodGrove_Text_NickDefeat:
	.string "What??$"

ErewoodGrove_Text_NateDefeat:
	.string "That was unexpected.$"

ErewoodGrove_Text_NateUgh:
	.string "Ugh, we must have overexerted\n"
	.string "ourselves in that tree hollow.$"

ErewoodGrove_Text_JamesWon:
	.string "Hah we beat you fair and square!\n"
	.string "Now let us know what you two are\l"
	.string "up to!$"

ErewoodGrove_Text_NickOneThing:
	.string "Brother, there's only one thing\n"
	.string "we can do...$"

ErewoodGrove_Movement_NickMove1:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	step_end

ErewoodGrove_Movement_NateMove1:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	step_end

ErewoodGrove_Movement_NickMove2:
	walk_fast_down
	walk_fast_left
	face_up
	step_end

ErewoodGrove_Movement_NateMove2:
	walk_fast_down
	walk_fast_right
	face_up
	step_end

ErewoodGrove_Movement_PushedIn:
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

ErewoodGrove_Text_NateCantSay:
	.string "Well I can't say that shoving a couple\n"
	.string "of kids down a hole is our proudest\l"
	.string "moment, but it had to be done.$"

ErewoodGrove_Text_NateEscape:
	.string "You remembered to leave an Escape\n"
	.string "Rope down there right?$"

ErewoodGrove_Text_NickUhh:
	.string "Uhh I think so?$"

ErewoodGrove_Text_NateEhh:
	.string "Eh either way it'll be fine.\n"
	.string "Let's go.$"


ErewoodGrove_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ErewoodGrove_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ErewoodGrove_OnFrame
	.byte 0

ErewoodGrove_OnTransition:
	call_if_eq VAR_STORY, 14, ErewoodGrove_EventScript_JamesLocation
	end

ErewoodGrove_OnFrame:
	map_script_2 VAR_STORY, 14, ErewoodGrove_EventScript_PostEscapeRope
	.2byte 0

ErewoodGrove_EventScript_JamesLocation::
	setobjectxyperm LOCALID_EREWOOD_JAMES, 25, 49
	removeobject LOCALID_EREWOOD_JAMES
	delay 1
	addobject LOCALID_EREWOOD_JAMES
	setobjectmovementtype LOCALID_EREWOOD_JAMES, MOVEMENT_TYPE_FACE_LEFT
	return

ErewoodGrove_EventScript_PostEscapeRope::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	setspeaker Speaker_James
	msgbox ErewoodGrove_Text_JamesExit, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EREWOOD_JAMES, Common_Movement_QuestionMark
	waitmovement 0
	setspeaker Speaker_James
	msgbox ErewoodGrove_Text_JamesLeave, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STORY, 15
	applymovement LOCALID_EREWOOD_JAMES, Common_Movement_FaceDown
	waitmovement 0
	delay 10
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_EREWOOD_JAMES
	waitfieldeffect FLDEFF_NPCFLY_OUT
	setflag FLAG_HIDE_EREWOOD_JAMES
	releaseall
	end

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
	clearflag FLAG_HIDE_EREWOOD_JAMES
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
	playse SE_M_CUT
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
	special RemoveCameraObject
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
	special SpawnCameraObject
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
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
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
	clearflag FLAG_HIDE_EREWOOD_NICKNATE
	special RemoveCameraObject
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

ErewoodGrove_EventScript_Hollow1::
	lockall
	msgbox ErewoodGrove_Text_ClimbHollow, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, ErewoodGrove_EventScript_WarpHollow1
	releaseall
	end

ErewoodGrove_EventScript_WarpHollow1::
	playse SE_FALL
	warpsilent MAP_EREWOOD_GROVE_B1F, 28, 40
	releaseall
	end

ErewoodGrove_EventScript_Hollow2::
	lockall
	msgbox ErewoodGrove_Text_ClimbHollow, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, ErewoodGrove_EventScript_WarpHollow2
	releaseall
	end

ErewoodGrove_EventScript_WarpHollow2::
	playse SE_FALL
	warpsilent MAP_EREWOOD_GROVE_B1F, 55, 31
	releaseall
	end

ErewoodGrove_EventScript_Hollow3::
	lockall
	msgbox ErewoodGrove_Text_ClimbHollow, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, ErewoodGrove_EventScript_WarpHollow3
	releaseall
	end

ErewoodGrove_EventScript_WarpHollow3::
	playse SE_FALL
	warpsilent MAP_EREWOOD_GROVE_B1F, 57, 3
	releaseall
	end

ErewoodGrove_EventScript_Hollow4::
	lockall
	msgbox ErewoodGrove_Text_ClimbHollow, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, ErewoodGrove_EventScript_WarpHollow4
	releaseall
	end

ErewoodGrove_EventScript_WarpHollow4::
	playse SE_FALL
	warpsilent MAP_EREWOOD_GROVE_B1F, 19, 6
	releaseall
	end

ErewoodGrove_EventScript_Hollow5::
	lockall
	msgbox ErewoodGrove_Text_ClimbHollow, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, ErewoodGrove_EventScript_WarpHollow5
	releaseall
	end

ErewoodGrove_EventScript_WarpHollow5::
	playse SE_FALL
	warpsilent MAP_EREWOOD_GROVE_B1F, 6, 16
	releaseall
	end

ErewoodGrove_Text_ClimbHollow:
	.string "Climb into the tree hollow?$"

ErewoodGrove_Text_JamesExit:
	.string "Whew I'm glad we finally made it out\n"
	.string "of that tree hollow!\p"
	.string "It seems like those two weirdos are\n"
	.string "gone now, off to complete whatever\l"
	.string "'mission' they were talking about.$"

ErewoodGrove_Text_JamesLeave:
	.string "Who are the 'Chosen' they were\n"
	.string "talking about though?\l"
	.string "And what do they want in the quarry?\p"
	.string "I'm assuming they are talking about\n"
	.string "the Coalscorch Quarry outside of\l"
	.string "Sundara Village,\p"
	.string "but that's just a regular rock\n"
	.string "quarry, I don't see how there could\l"
	.string "be anything special there.\p"
	.string "Whatever is there, the Professor\n"
	.string "definitely needs to know about it.\p"
	.string "I'll go let him know, you should\n"
	.string "follow those guys and stop whatever\l"
	.string "they are trying to do!$"

ErewoodGrove_Movement_JamesGoToProf:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	end

Speaker_Ely:
    .string "Ely$"

ErewoodGrove_EventScript_Ely::
	trainerbattle_single TRAINER_ELY, ErewoodGrove_Text_ElyIntro, ErewoodGrove_Text_ElyDefeat
	setspeaker Speaker_Ely
	msgbox ErewoodGrove_Text_ElyPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Gordon:
    .string "Gordon$"

ErewoodGrove_EventScript_Gordon::
	trainerbattle_single TRAINER_GORDON, ErewoodGrove_Text_GordonIntro, ErewoodGrove_Text_GordonDefeat
	setspeaker Speaker_Gordon
	msgbox ErewoodGrove_Text_GordonPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Margo:
    .string "Margo$"

ErewoodGrove_EventScript_Margo::
	trainerbattle_single TRAINER_MARGO, ErewoodGrove_Text_MargoIntro, ErewoodGrove_Text_MargoDefeat
	setspeaker Speaker_Margo
	msgbox ErewoodGrove_Text_MargoPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Zeke:
    .string "Zeke$"

ErewoodGrove_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE, ErewoodGrove_Text_ZekeIntro, ErewoodGrove_Text_ZekeDefeat
	setspeaker Speaker_Zeke
	msgbox ErewoodGrove_Text_ZekePostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Micah:
    .string "Micah$"

ErewoodGrove_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, ErewoodGrove_Text_MicahIntro, ErewoodGrove_Text_MicahDefeat
	setspeaker Speaker_Micah
	msgbox ErewoodGrove_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Isaac:
    .string "Isaac$"

ErewoodGrove_EventScript_Isaac::
	trainerbattle_single TRAINER_ISAAC, ErewoodGrove_Text_IsaacIntro, ErewoodGrove_Text_IsaacDefeat
	setspeaker Speaker_Isaac
	msgbox ErewoodGrove_Text_IsaacPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Sylvia:
    .string "Sylvia$"

ErewoodGrove_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, ErewoodGrove_Text_SylviaIntro, ErewoodGrove_Text_SylviaDefeat
	setspeaker Speaker_Sylvia
	msgbox ErewoodGrove_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Ed:
    .string "Ed$"

ErewoodGrove_EventScript_Ed::
	lockall
	faceplayer
	switch VAR_EGG_QUEST
	case 0, ErewoodGrove_EventScript_EdDefault
	case 1, ErewoodGrove_EventScript_EdBattle
	case 2, ErewoodGrove_EventScript_EdLeave
	end

ErewoodGrove_EventScript_EdDefault::
	lockall
	faceplayer
	setspeaker Speaker_Ed
	msgbox ErewoodGrove_Text_EdDefault, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

ErewoodGrove_EventScript_EdBattle::
	lockall
	faceplayer
	setspeaker Speaker_Ed
	msgbox ErewoodGrove_Text_EdBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ED, ErewoodGrove_Text_EdDefeat
	setspeaker Speaker_Ed
	msgbox ErewoodGrove_Text_EdPost, MSGBOX_DEFAULT
	closemessage
	setvar VAR_EGG_QUEST, 2
	setflag FLAG_HIDE_EREWOOD_EGG_THIEF
	releaseall
	end

ErewoodGrove_EventScript_EdLeave::
	lockall
	faceplayer
	setspeaker Speaker_Ed
	msgbox ErewoodGrove_Text_EdLeave, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

ErewoodGrove_Text_EdDefault:
	.string "Grr I can't find the exit, where am\n"
	.string "I supposed to go? I need to get out\l"
	.string "of here fast...\p"
	.string "Hey, stop bothering me!\n"
	.string "I'm trying to think here!$"

ErewoodGrove_Text_EdBattle::
	.string "Grr I can't find the exit, where am\n"
	.string "I supposed to go? I need to get out\l"
	.string "of here fast...\p"
	.string "Huh? Stolen Pokémon eggs?\n"
	.string "N-no, I don't know anything about that!\l"
	.string "Now leave me alone!\p"
	.string "...\p"
	.string "Why are you still here!\n"
	.string "Go away!\p"
	.string "...\p"
	.string "Grr fine, I give up! I took those\n"
	.string "stupid Pokémon eggs to make a pretty\l"
	.string "profit, but some I'm stuck here!\p"
	.string "I can't have you telling anyone, I'll\n"
	.string "take all my rage out on you!$"

ErewoodGrove_Text_EdDefeat::
	.string "This can't be happening!$"

ErewoodGrove_Text_EdPost::
	.string "Grr I can't believe I lost!\p"
	.string "This was supposed to be easy money,\n"
	.string "but getting lost in the woods and\l"
	.string "losing to a child is humiliating!\p"
	.string "These eggs are more trouble than\n"
	.string "they're worth!\p"
	.string "Fine, have it your way. I'll return\n"
	.string "the eggs, just leave me alone!$"

ErewoodGrove_Text_EdLeave::
	.string "Fine, have it your way. I'll return\n"
	.string "the eggs, just leave me alone!$"



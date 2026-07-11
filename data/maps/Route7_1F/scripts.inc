Route7_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route7_1F_OnFrame
	.byte 0

Route7_1F_OnFrame:
	map_script_2 VAR_STORY, 3, Route7_1F_EventScript_Entrance
	map_script_2 VAR_STORY, 4, Route7_1F_EventScript_Unknown
	.2byte 0

Route7_1F_EventScript_Entrance::
	lockall
	delay 10
	setflag FLAG_ROUTE7_1F_UNOWN
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp2
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	delay 5
	applymovement LOCALID_JAMES, Route7_1F_Movement_JamesEnter
	applymovement LOCALID_MACHOP, Route7_1F_Movement_JamesEnter
	delay 3
	applymovement LOCALID_ISABEL, Route7_1F_Movement_IsabelEnter
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesLetsGo, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	waitmoncry
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	applymovement LOCALID_JAMES, Common_Movement_FaceUp
	applymovement LOCALID_ISABEL, Common_Movement_FaceUp
	applymovement LOCALID_MACHOP, Route7_1F_Movement_MachopEnter
	waitmovement 0
	applymovement LOCALID_ISABEL, Common_Movement_ExclamationMark
	playse SE_PIN
	setspeaker Speaker_Isabel
	msgbox Route_7_1F_Text_IsabelFindMon, MSGBOX_DEFAULT
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	applymovement LOCALID_JAMES, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_ZUBAT_1, Route7_1F_Movement_Zubat1Enter
	waitmovement 0
	setobjectmovementtype LOCALID_ZUBAT_1, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesGetThem, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_ISABEL, Common_Movement_ExclamationMark
	delay 1
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 2
	applymovement LOCALID_JAMES, Common_Movement_QuestionMark
	waitmovement 0
	applymovement LOCALID_ISABEL, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_JAMES, Common_Movement_FaceLeft
	applymovement LOCALID_MACHOP, Common_Movement_FaceLeft
	applymovement LOCALID_ZUBAT_2, Route7_1F_Movement_Zubat2Enter
	waitmovement 0
	setobjectmovementtype LOCALID_ZUBAT_2, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesNowTwo, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_ISABEL, Common_Movement_ExclamationMark
	delay 1
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ISABEL, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JAMES, Common_Movement_FaceRight
	applymovement LOCALID_MACHOP, Common_Movement_FaceRight
	applymovement LOCALID_ZUBAT_3, Route7_1F_Movement_Zubat3Enter
	waitmovement 0
	setobjectmovementtype LOCALID_ZUBAT_3, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesOhNo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ISABEL, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	setspeaker Speaker_Isabel
	msgbox Route_7_1F_Text_IsabelNotGood, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesRun, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAMERA, Common_Movement_WalkDownFast
	applymovement LOCALID_JAMES, Route7_1F_Movement_JamesRun
	delay 3
	applymovement LOCALID_ISABEL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 1
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MACHOP, Route7_1F_Movement_MachopRun
	delay 10
	applymovement LOCALID_ISABEL, Route7_1F_Movement_IsabelRun
	delay 3
	applymovement LOCALID_PLAYER, Route7_1F_Movement_PlayerRun
	delay 6
	special RemoveCameraObject
	setvar VAR_STORY, 4
	playse SE_EXIT
	setflag FLAG_ROUTE7_1F_ZUBAT
	warpsilent MAP_ROUTE7_1F, 2
	releaseall
	end

Route7_1F_Movement_IsabelEnter:
	walk_down
	walk_down
	walk_left
	step_end

Route7_1F_Movement_JamesEnter:
	walk_right
	walk_down
	walk_right
	step_end

Route_7_1F_Text_JamesLetsGo:
	.string "Now that we are all here, let's\n"
	.string "go find some Pokémon! \p"
	.string "Go Riolu!$"

Route7_1F_Movement_MachopEnter:
	walk_up
	walk_right
	walk_right
	face_up
	step_end

Route_7_1F_Text_IsabelFindMon:
	.string "Look, here comes one now!$"

Route7_1F_Movement_Zubat1Enter:
	walk_down
	walk_down
	walk_down
	step_end

Route7_1F_Movement_Zubat2Enter:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route7_1F_Movement_Zubat3Enter:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route_7_1F_Text_JamesGetThem:
	.string "Here we go, it's a Zubat!\n"
	.string "Riolu, let's take him on!$"

Route_7_1F_Text_JamesNowTwo:
	.string "Uhh there's two now...\p"
	.string "W-we can still do this!$"

Route_7_1F_Text_JamesOhNo:
	.string "...oh no...$"

Route_7_1F_Text_IsabelNotGood:
	.string "This is not good.\p"
	.string "James, we really need to-$"

Route_7_1F_Text_JamesRun:
	.string "RUN!$"

Route7_1F_Movement_JamesRun:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Route7_1F_Movement_MachopRun:
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Route7_1F_Movement_IsabelRun:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Route7_1F_Movement_PlayerRun:
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Route7_1F_EventScript_Unknown::
	lockall
	setobjectxyperm LOCALID_JAMES, 12, 32
	setobjectxyperm LOCALID_ISABEL, 14, 32
	setobjectxyperm LOCALID_MACHOP, 11, 32
	setobjectxyperm LOCALID_ZUBAT_1, 13, 40
	setobjectxyperm LOCALID_ZUBAT_2, 12, 40
	setobjectxyperm LOCALID_ZUBAT_3, 14, 40
	setobjectmovementtype LOCALID_JAMES, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_ISABEL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_MACHOP, MOVEMENT_TYPE_FACE_UP
	applymovement LOCALID_PLAYER, Route7_1F_Movement_PlayerSecondRoom
	waitmovement 0
	delay 10
	applymovement LOCALID_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesDeadEnd, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ISABEL, Common_Movement_FaceLeft
	waitmovement 0
	delay 5
	applymovement LOCALID_JAMES, Common_Movement_FaceRight
	setspeaker Speaker_Isabel
	msgbox Route_7_1F_Text_IsabelWhy, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_James
	applymovement LOCALID_JAMES, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox Route_7_1F_Text_JamesHey, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Isabel
	msgbox Route_7_1F_Text_IsabelRuins, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ISABEL, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker Speaker_Isabel
	msgbox Route_7_1F_Text_IsabelRuinsTwo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JAMES, Common_Movement_FaceUp
	applymovement LOCALID_ISABEL, Common_Movement_WalkUp
	waitmovement 0
	setspeaker Speaker_Isabel
	msgbox Route_7_1F_Text_IsabelRuinsThree, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesNotNow, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_ZUBAT, CRY_MODE_NORMAL
	waitmoncry
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown
	applymovement LOCALID_ISABEL, Common_Movement_WalkDown
	delay 3
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_JAMES, Common_Movement_FaceDown
	applymovement LOCALID_MACHOP, Common_Movement_FaceDown
	waitmovement 0
	addobject LOCALID_ZUBAT_1
	addobject LOCALID_ZUBAT_2
	addobject LOCALID_ZUBAT_3
	applymovement LOCALID_ZUBAT_1, Route7_1F_Movement_ZubatRuins
	applymovement LOCALID_ZUBAT_2, Route7_1F_Movement_ZubatRuins
	applymovement LOCALID_ZUBAT_3, Route7_1F_Movement_ZubatRuins
	setobjectmovementtype LOCALID_ZUBAT_1, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectmovementtype LOCALID_ZUBAT_2, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectmovementtype LOCALID_ZUBAT_3, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesLikeNow, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Isabel
	msgbox Route_7_1F_Text_IsabelWhatWeDo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JAMES, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesAttacking, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JAMES, Common_Movement_FaceDown
	waitmovement 0
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_ISABEL, Common_Movement_ExclamationMark
	delay 2
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 1
	applymovement LOCALID_JAMES, Common_Movement_QuestionMark
	delay 10
	applymovement LOCALID_JAMES, Common_Movement_FaceLeft
	delay 10
	applymovement LOCALID_JAMES, Common_Movement_FaceUp
	delay 10
	applymovement LOCALID_JAMES, Common_Movement_FaceRight
	delay 10
	applymovement LOCALID_JAMES, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesWhat, MSGBOX_DEFAULT
	closemessage
	fadescreenspeed FADE_TO_BLACK, 2
	addobject LOCALID_UNOWN
	fadescreenspeed FADE_FROM_BLACK, 2
	delay 5
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_ISABEL, Common_Movement_ExclamationMark
	delay 2
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 1
	applymovement LOCALID_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesWhatIsThat, MSGBOX_DEFAULT
	closemessage
	delay 5
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
	waitmoncry
	special SavePlayerParty
	givemon SPECIES_UNOWN_QUESTION, 15, ITEM_NONE, ITEM_POKE_BALL, NATURE_MODEST, 0, MON_GENDERLESS, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_POWER_GEM, MOVE_MOONBLAST, TRUE, FALSE, TYPE_PSYCHIC
	setwildbattle SPECIES_ZUBAT, 3
	setflag FLAG_NO_WILD_RUN
	dowildbattle
	clearflag FLAG_NO_WILD_RUN
	special LoadPlayerParty
	playse SE_FAINT
	removeobject LOCALID_ZUBAT_1
	delay 8
	playse SE_PIN
	applymovement LOCALID_ISABEL, Common_Movement_ExclamationMark
	delay 2
	applymovement LOCALID_JAMES, Common_Movement_ExclamationMark
	delay 4
	applymovement LOCALID_ZUBAT_2, Route7_1F_Movement_ZubatAway
	applymovement LOCALID_ZUBAT_3, Route7_1F_Movement_ZubatAway
	waitmovement 0
	applymovement LOCALID_UNOWN, Common_Movement_FaceUp
	delay 4
	playmoncry SPECIES_UNOWN, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_UNOWN, Common_Movement_FaceDown
	waitmovement 0
	delay 5
	fadescreenspeed FADE_TO_BLACK, 2
	removeobject LOCALID_UNOWN
	fadescreenspeed FADE_FROM_BLACK, 2
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesGone, MSGBOX_DEFAULT
	closemessage
	setspeaker Speaker_Isabel
	msgbox Route_7_1F_Text_IsabelGone, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_7_1F_Text_JamesCrazy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ISABEL, Common_Movement_FaceLeft
	setspeaker Speaker_Isabel
	msgbox Route_7_1F_Text_IsabelLeave, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAMERA, Common_Movement_WalkUpFaster
	special RemoveCameraObject
	setvar VAR_STORY, 5
	clearflag FLAG_ROUTE7_PINE 
	playse SE_EXIT
	warpsilent MAP_ROUTE7, 0
	releaseall
	end

Route7_1F_Movement_PlayerSecondRoom:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Route_7_1F_Text_JamesDeadEnd:
	.string "It's a dead end!$"

Route_7_1F_Text_IsabelWhy:
	.string "Why did you lead us into a cave with\n"
	.string "a dead end?!$"

Route_7_1F_Text_JamesHey:
	.string "Hey I didn't know it was a dead\n"
	.string "end! Besides, look at these weird\l"
	.string "markings!\p"
	.string "You're welcome! $"

Route_7_1F_Text_IsabelRuins:
	.string "I'll thank you if we survive this!$"

Route_7_1F_Text_IsabelRuinsTwo:
	.string "Wait did you say weird markings?$"

Route_7_1F_Text_IsabelRuinsThree:
	.string "Oh wow these are really exquisite!\p"
	.string "I haven't seen anything like these\n"
	.string "runes before!\p"
	.string "And I didn't know there was a cave\n"
	.string "here, there's no record of it.$"

Route_7_1F_Text_JamesNotNow:
	.string "Now is not the time!\n"
	.string "We need to leave here!$"

Route7_1F_Movement_ZubatRuins:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route_7_1F_Text_JamesLikeNow:
	.string "Like now!$"

Route_7_1F_Text_IsabelWhatWeDo:
	.string "We're trapped!\n"
	.string "What are we going to do?$"

Route_7_1F_Text_JamesAttacking:
	.string "They're going to attack!$"

Route_7_1F_Text_JamesWhat:
	.string "What was that?$"

Route_7_1F_Text_JamesWhatIsThat:
	.string "What's going on?$"

Route7_1F_Movement_ZubatAway:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
	
Route_7_1F_Text_JamesGone:
	.string "It's gone!$"

Route_7_1F_Text_IsabelGone:
	.string "And the Zubat are as well!\n"
	.string "{PLAYER} that was incredible.\l"
	.string "You were controlling that Pokémon!$"

Route_7_1F_Text_JamesCrazy:
	.string "That was crazy!\n"
	.string "How did you do that?$"

Route_7_1F_Text_IsabelLeave:
	.string "We can talk about that in a moment,\n"
	.string "let's get out of here first!$"

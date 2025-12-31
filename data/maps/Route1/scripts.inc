Route1_MapScripts::
	.byte 0

Route_1_EventScript_JamesEntrance_1::
	delay 5
	applymovement LOCALID_JAMES, Common_Movement_FaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JAMES, Route_1_Movement_JamesEntrance_1
	waitmovement 0
	call Route_1_EventScript_JamesBattle
	releaseall
	end

Route_1_EventScript_JamesEntrance_2::
	delay 5
	applymovement LOCALID_JAMES, Common_Movement_FaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JAMES, Route_1_Movement_JamesEntrance_2
	waitmovement 0
	call Route_1_EventScript_JamesBattle
	releaseall
	end

Route_1_EventScript_JamesEntrance_3::
	delay 5
	applymovement LOCALID_JAMES, Common_Movement_FaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_JAMES, Route_1_Movement_JamesEntrance_3
	waitmovement 0
	call Route_1_EventScript_JamesBattle
	releaseall
	end

Route_1_Movement_JamesEntrance_1:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route_1_Movement_JamesEntrance_2:
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

Route_1_Movement_JamesEntrance_3:
	walk_up
	walk_left
	walk_left
	step_end

Route_1_EventScript_JamesBattle::
	lockall
	setspeaker Speaker_James
	msgbox Route_1_Text_JamesEnter, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_JAMES_1, Route_1_Text_JamesDefeat
	setspeaker Speaker_James
	msgbox Route_1_Text_JamesLeave, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JAMES, Common_Movement_FaceDown
	waitmovement 0
	delay 15
	applymovement LOCALID_JAMES, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker Speaker_James
	msgbox Route_1_Text_JamesRival, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	delay 8
	applymovement LOCALID_JAMES, Route_1_Movement_JamesDefeat
	waitmovement 0
	removeobject LOCALID_JAMES
	setvar VAR_STORY, 10
	setflag FLAG_JAMES_ROUTE_1
	releaseall
	end

Route_1_Text_JamesEnter:
	.string "There you are {PLAYER}!\p"
	.string "Machop and I have been training, we\n"
	.string "are ready for our first Pokémon battle!\p"
	.string "Hope you're ready for a fight!$"

Route_1_Text_JamesDefeat:
	.string "Whoa {PLAYER}, you're good!$"

Route_1_Text_JamesLeave:
	.string "You really are a natural, {PLAYER}.\p"
	.string "I even got Machop before you got your\n"
	.string "Pokémon, and you still beat us.$"

Route_1_Text_JamesRival:
	.string "I guess I shouldn't be that hard on\n"
	.string "myself, we did get our Pokémon on\p"
	.string "the same day.\p"
	.string "That's it, we'll just have to train\n"
	.string "harder and win next time!\p"
	.string "First I have to ask my dad though,\n"
	.string "that will be the hard part.\p"
	.string "We will see you soon, I'm sure of it!$"

Route_1_Movement_JamesDefeat:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


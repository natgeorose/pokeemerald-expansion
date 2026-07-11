QuilspringTown_MapScripts::
	.byte 0

QuilspringTown_EventScript_Jim::
	lockall
	setspeaker Speaker_Jim
	msgbox QuilspringTown_Text_Jim, MSGBOX_NPC
	releaseall
	end

QuilspringTown_Text_Jim:
	.string "I'm sorry, the Gym Leader isn't in at\n"
	.string "the moment. She's off at a book signing\l"
	.string "I believe. You'll have to come back.$"

QuilspringTown_EventScript_SchoolKid::
	lockall
	setspeaker Speaker_Boy
	msgbox QuilspringTown_Text_SchoolKid, MSGBOX_NPC
	releaseall
	end

QuilspringTown_Text_SchoolKid:
	.string "The serene pond here helps me take my\n"
	.string "mind off of school and relax. You have\l"
	.string "to be able to take a break from things.$"

QuilspringTown_EventScript_Girl::
	lockall
	setspeaker Speaker_Girl
	msgbox QuilspringTown_Text_Girl, MSGBOX_NPC
	releaseall
	end

QuilspringTown_Text_Girl:
	.string "You came here from Cairwind Town?\n"
	.string "That's so far away!$"

QuilspringTown_EventScript_Boy::
	lockall
	setspeaker Speaker_Boy
	msgbox QuilspringTown_Text_Boy, MSGBOX_NPC
	releaseall
	end

QuilspringTown_Text_Boy:
	.string "This is my favorite study spot!$"

QuilspringTown_EventScript_Woman::
	lockall
	setspeaker Speaker_Woman
	msgbox QuilspringTown_Text_Woman, MSGBOX_NPC
	releaseall
	end

QuilspringTown_Text_Woman:
	.string "Quilspring Town is best known for the\n"
	.string "University, led by Professor Pine.\p"
	.string "But there is also a Gym, not to mention\n"
	.string "the Milk Bar as well. It's a great\l"
	.string "place to live!$"

QuilspringTown_EventScript_SignMilkBar::
	msgbox QuilspringTown_Text_SignMilkBar, MSGBOX_SIGN
	end

QuilspringTown_Text_SignMilkBar:
	.string "Quilspring Town Milk Bar\n"
	.string "“The hottest spot in town!”$"

QuilspringTown_EventScript_University::
	msgbox QuilspringTown_Text_University, MSGBOX_SIGN
	end

QuilspringTown_Text_University:
	.string "Serenado University$"

QuilspringTown_EventScript_Gym::
	msgbox QuilspringTown_Text_Gym, MSGBOX_SIGN
	end

QuilspringTown_Text_Gym:
	.string "Quilspring Town Gym\n"
	.string "Leader: Nyx\l"
	.string "Level Cap: 14$"

QuilspringTown_EventScript_PineHouse::
	msgbox QuilspringTown_Text_PineHouse, MSGBOX_SIGN
	end

QuilspringTown_Text_PineHouse:
	.string "Professor Pine's House$"

QuilspringTown_EventScript_TownSign::
	msgbox QuilspringTown_Text_TownSign, MSGBOX_SIGN
	end

QuilspringTown_Text_TownSign:
	.string "Quilspring Town\n"
	.string "“Where knowledge is born.”$"

QuilspringTown_EventScript_JamesInitiate::
	lockall
	clearflag FLAG_HIDE_QUILSPRING_JAMES
	addobject LOCALID_QUIL_JAMES
	setspeaker Speaker_James
	msgbox QuilspringTown_Text_JamesWait, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	delay 5
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_QUIL_JAMES, QuilspringTown_Movement_JamesEnter
	waitmovement 0
	setspeaker Speaker_James
	msgbox QuilspringTown_Text_JamesMadeIt, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_JAMES_2, QuilspringTown_Text_JamesDefeat
	applymovement LOCALID_QUIL_JAMES, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_James
	msgbox QuilspringTown_Text_JamesWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_QUIL_JAMES, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker Speaker_James
	msgbox QuilspringTown_Text_JamesLeave, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_QUIL_JAMES, QuilspringTown_Movement_JamesLeave
	waitmovement 0
	setvar VAR_STORY, 12
	removeobject LOCALID_QUIL_JAMES
	setflag FLAG_HIDE_QUILSPRING_JAMES
	clearflag FLAG_HIDE_QUILSPRING_ISABEL
	releaseall
	end

QuilspringTown_Text_JamesWait:
	.string "Wait up!$"

QuilspringTown_Movement_JamesEnter:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_diag_northwest
	walk_left
	walk_left
	step_end

QuilspringTown_Movement_JamesLeave:
	walk_right
	walk_right
	walk_diag_southeast
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

QuilspringTown_Text_JamesMadeIt:
	.string "Hi {PLAYER}, bet you weren't expecting\n"
	.string "to see me here!\p"
	.string "I was able to find a job that allowed\n"
	.string "me to come to Quilspring Town, now I\l"
	.string "can challenge the Gym and get stronger!\p"
	.string "And since it's a paying job I got my\n"
	.string "dad's approval to take it!\n"
	.string "...\p"
	.string "Of course that job was escorting Isabel\n"
	.string "here to study with Professor Pine.\p"
	.string "She went on and on about runes and\n"
	.string "texts the entire time, it was brutal...\p"
	.string "But I made it here! Now it seems like\n"
	.string "we are both ready to challenge the Gym!\l"
	.string "Let's battle to see who will go first!$"

QuilspringTown_Text_JamesDefeat:
	.string "Ugh... Not again...$"

QuilspringTown_Text_JamesWrong:
	.string "I don't know what I did wrong, I\n"
	.string "thought I had gotten so much\l"
	.string "stronger on the way here.$"

QuilspringTown_Text_JamesLeave:
	.string "But that shouldn't take away from\n"
	.string "your victory, you're definitely\l"
	.string "ready to challenge the Gym.\p"
	.string "Maybe I'll go study at the University\n"
	.string "and see if there's something I'm\l"
	.string "missing as a Trainer...\p"
	.string "Good luck on your Gym battle!\n"
	.string "I'll be cheering for you.$"



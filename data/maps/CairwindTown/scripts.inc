CairwindTown_MapScripts::
	.byte 0

CairwindTown_EventScript_TownSign::
	msgbox CairwindTown_Text_TownSign, MSGBOX_SIGN
	end

CairwindTown_Text_TownSign:
	.string "Cairwind Town\n"
	.string "“Where the winds of adventure blow.”$"

CairwindTown_EventScript_PlayerHouseSign::
	msgbox CairwindTown_Text_PlayerHouseSign, MSGBOX_SIGN
	end

CairwindTown_Text_PlayerHouseSign:
	.string "{PLAYER}'s House$"

CairwindTown_EventScript_JamesHouseSign::
	msgbox CairwindTown_Text_JamesHouseSign, MSGBOX_SIGN
	end

CairwindTown_Text_JamesHouseSign:
	.string "James' House$"

CairwindTown_EventScript_IsabelHouseSign::
	msgbox CairwindTown_Text_IsabelHouseSign, MSGBOX_SIGN
	end

CairwindTown_Text_IsabelHouseSign:
	.string "Isabel's House$"

CairwindTown_EventScript_StopExplore::
	lockall
	msgbox CairwindTown_Text_StopExplore
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

CairwindTown_Text_StopExplore:
	.string "I should follow James before going\n"
	.string "anywhere else.$"

Speaker_James:
    .string "James$"

CairwindTown_EventScript_JamesSpeech::
	lockall
	applymovement LOCALID_JAMES, CairwindTown_Movement_JamesBeforeSpeech
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	playse SE_PIN
	setspeaker Speaker_James
	msgbox CairwindTown_Text_JamesSpeech, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_JAMES, CairwindTown_Movement_JamesAfterSpeech
	waitmovement 0
	removeobject LOCALID_JAMES
	setvar VAR_STORY, 3
	setflag FLAG_HIDE_CAIRWIND_JAMES
	releaseall
	end

CairwindTown_Movement_JamesBeforeSpeech:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	emote_exclamation_mark
	step_end

CairwindTown_Text_JamesSpeech:
	.string "Hey {PLAYER}, there you are!\p"
	.string "You'll never guess what happened\n"
	.string "today, I got my first Pokémon!\p"
	.string "My dad finally gave in and let me\n"
	.string "have a Pokémon of my own!\p"
	.string "It's only a Riolu, and I'm only\n"
	.string "supposed to use him to help cut\p"
	.string "down and move trees for my dad's\n"
	.string "business, but it's a Pokémon!\p"
	.string "Now that the Professor is in town\n"
	.string "and dad is distracted,\p"
	.string "it's the perfect time to go up to\n"
	.string "Route 7 and start training him!\p"
	.string "You better sneak away and follow us!\n"
	.string "Isabel will be there too, I made the\p"
	.string "mistake of telling her and she\n"
	.string "insisted on coming, blabbering\p"
	.string "about research and ruins and whatnot.\n"
	.string "We'll be waiting just north of town,\l"
	.string "you better be there soon!$"

CairwindTown_Movement_JamesAfterSpeech:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Speaker_Boy:
    .string "Boy$"

CairwindTown_EventScript_BoyLeft::
	lockall
	setspeaker Speaker_Boy
	msgbox CairwindTown_Text_BoyLeft, MSGBOX_NPC
	closemessage
	releaseall
	end

CairwindTown_Text_BoyLeft:
	.string "Professor Pine is so cool,\n"
	.string "I want to be just like him!$"

Speaker_Lass:
    .string "Lass$"

CairwindTown_EventScript_Lass::
	lockall
	setspeaker Speaker_Lass
	msgbox CairwindTown_Text_Lass, MSGBOX_NPC
	closemessage
	releaseall
	end

CairwindTown_Text_Lass:
	.string "I wonder if Professor Pine\n"
	.string "will give me a Pokémon.$"

CairwindTown_EventScript_LittleBoy::
	lockall
	setspeaker Speaker_Boy
	msgbox CairwindTown_Text_LittleBoy, MSGBOX_NPC
	closemessage
	releaseall
	end

CairwindTown_Text_LittleBoy:
	.string "I'm spending the whole day\n"
	.string "with my big sister!$"

CairwindTown_EventScript_Maniac::
	lockall
	setspeaker Speaker_Scientist
	msgbox CairwindTown_Text_Maniac, MSGBOX_NPC
	closemessage
	releaseall
	end

CairwindTown_Text_Maniac:
	.string "I'm not even interested in Pokémon,\n"
	.string "I just want to do research with\l"
	.string "Professor Pine!$"

Speaker_Cameraman:
    .string "Cameraman$"

CairwindTown_EventScript_Camerman::
	lockall
	setspeaker Speaker_Cameraman
	msgbox CairwindTown_Text_Cameraman, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

CairwindTown_Text_Cameraman:
	.string "Professor Pine is quite a presence,\n"
	.string "I have to get this all on camera.$"

Speaker_Girl:
    .string "Girl$"

CairwindTown_EventScript_GirlWalk::
	lockall
	setspeaker Speaker_Girl
	msgbox CairwindTown_Text_GirlWalk, MSGBOX_NPC
	closemessage
	releaseall
	end

CairwindTown_Text_GirlWalk:
	.string "Cairwind Town is quiet now that\n"
	.string "Professor Pine is gone.$"

CairwindTown_EventScript_LeaveBeforeMap::
	lockall
	msgbox CairwindTown_Text_LeaveBeforeMap, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end

CairwindTown_Text_LeaveBeforeMap:
	.string "I should talk to Mom before I leave.$"

Speaker_Elder:
    .string "Elder$"

CairwindTown_EventScript_Expert::
	lockall
	setspeaker Speaker_Elder
	msgbox CairwindTown_Text_Expert, MSGBOX_NPC
	releaseall
	end

CairwindTown_Text_Expert:
	.string "Ahh I do love the fresh mountain\n"
	.string "air, it keeps me feeling young.$"

CairwindTown_EventScript_BoyPost::
	lockall
	setspeaker Speaker_Boy
	msgbox CairwindTown_Text_BoyPost, MSGBOX_NPC
	releaseall
	end

CairwindTown_Text_BoyPost:
	.string "Professor Pine is so cool, I\n"
	.string "can't believe he visited here!$"

CairwindTown_EventScript_LassPost::
	lockall
	setspeaker Speaker_Lass
	msgbox CairwindTown_Text_LassPost, MSGBOX_NPC
	releaseall
	end

CairwindTown_Text_LassPost:
	.string "You can only carry 6 Pokémon on\n"
	.string "you at any given time, so make sure\p"
	.string "to switch them out occasionally!$"

CairwindTown_EventScript_GirlPost::
	lockall
	setspeaker Speaker_Girl
	msgbox CairwindTown_Text_GirlPost, MSGBOX_NPC
	releaseall
	end

CairwindTown_Text_GirlPost:
	.string "Cairwind Town is so peaceful,\n"
	.string "I want to stay here forever!$"


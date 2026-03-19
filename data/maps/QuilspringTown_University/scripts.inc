QuilspringTown_University_MapScripts::
	.byte 0

Speaker_Lecturer:
	.string "Lecturer$"

Speaker_Researcher:
	.string "Researcher$"

Speaker_WeirdBoy:
	.string "Weird Boy$"

QuilspringTown_University_EventScript_Start::
	msgbox QuilspringTown_University_Text_Start, MSGBOX_SIGN
	end

QuilspringTown_University_Text_Start:
	.string "The Dexnav can be accessed from the\n"
	.string "Start menu by pressing the L Button.\p"
	.string "When trying to catch a Pokémon using\n"
	.string "the Dexnav, first make sure you are\l"
	.string "walking before selecting the Pokémon.\p"
	.string "Creep up on the Pokémon to surprise it\n"
	.string "by holding the A Button.$"

QuilspringTown_University_EventScript_Select::
	msgbox QuilspringTown_University_Text_Select, MSGBOX_SIGN
	end

QuilspringTown_University_Text_Select:
	.string "The Trainer's Kit can be accessed by\n"
	.string "pressing the Select Button.\p"
	.string "Using the Trainer's Kit, you have access\n"
	.string "to the Infinite Repel, which repels all\l"
	.string "wild Pokémon indefinitely,\p"
	.string "the EXP Share, which allows all of your\n"
	.string "party Pokémon to gain experience, and\p"
	.string "the Camping Tent, which allows you to\n"
	.string "rest until a different time of day.\p"
	.string "In addition, you can return your\n"
	.string "following Pokémon to it's Poké Ball,\l"
	.string "and use any registered item.$"

QuilspringTown_University_EventScript_Lecturer::
	lockall
	setspeaker Speaker_Lecturer
	msgbox QuilspringTown_University_Text_Lecturer, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_Lecturer:
	.string "If you wish to listen to today's lesson\n"
	.string "on the stats of Pokémon, feel free to\l"
	.string "have a seat.$"

QuilspringTown_University_EventScript_ClassBoyOne::
	lockall
	setspeaker Speaker_Boy
	msgbox QuilspringTown_University_Text_ClassBoyOne, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_ClassBoyOne:
	.string "Pokémon have genetic traits called\n"
	.string "IVs, or Individual Values.\p"
	.string "These values can change how strong\n"
	.string "the Pokémon can become!$"

QuilspringTown_University_EventScript_ClassBoyTwo::
	lockall
	setspeaker Speaker_Boy
	msgbox QuilspringTown_University_Text_ClassBoyTwo, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_ClassBoyTwo:
	.string "Pokémon can obtain Effort Values,\n"
	.string "or EVs, through the use of vitamins.\p"
	.string "Vitamins are rare in Serenado though!$"

QuilspringTown_University_EventScript_ClassGirlOne::
	lockall
	setspeaker Speaker_Girl
	msgbox QuilspringTown_University_Text_ClassGirlOne, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_ClassGirlOne:
	.string "The nature of a Pokémon can increase\n"
	.string "or decrease it's stats.$"

QuilspringTown_University_EventScript_ClassGirlTwo::
	lockall
	setspeaker Speaker_Girl
	msgbox QuilspringTown_University_Text_ClassGirlTwo, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_ClassGirlTwo:
	.string "I wish the lecturer would slow down.\n"
	.string "I'm taking notes as fast as I can!$"

QuilspringTown_University_EventScript_Aide::
	lockall
	setspeaker Speaker_Researcher
	msgbox QuilspringTown_University_Text_Aide, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_Aide:
	.string "I serve as one of Professor Pine's\n"
	.string "research aides. He can be a bit\l"
	.string "demanding at times,\p"
	.string "but he holds himself to an even\n"
	.string "higher standard than us researchers.$"

QuilspringTown_University_EventScript_HallBoy::
	lockall
	setspeaker Speaker_Boy
	msgbox QuilspringTown_University_Text_HallBoy, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_HallBoy:
	.string "Serenado University is so big, I\n"
	.string "keep on getting lost here!$"

QuilspringTown_University_EventScript_Girls::
	lockall
	setspeaker Speaker_Girl
	msgbox QuilspringTown_University_Text_Girls, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_Girls:
	.string "Hey! The girl's dormitory is for\n"
	.string "female students only! Get out of\l"
	.string "here! You don't even go here!$"

QuilspringTown_University_EventScript_Boys::
	lockall
	setspeaker Speaker_Boy
	msgbox QuilspringTown_University_Text_Boys, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_Boys:
	.string "As nice as the dormitories are here,\n"
	.string "I still miss home...$"

QuilspringTown_University_EventScript_LoungeGirl::
	lockall
	setspeaker Speaker_Girl
	msgbox QuilspringTown_University_Text_LoungeGirl, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_LoungeGirl:
	.string "Professor Pine gives out the\n"
	.string "hardest assignments, I'm going to\l"
	.string "be up all night working!$"

QuilspringTown_University_EventScript_LoungeBoy::
	lockall
	goto_if_set FLAG_DEFEATED_QUILSPRING_GYM, QuilspringTown_University_EventScript_LoungeBoy_Post
	setspeaker Speaker_WeirdBoy
	msgbox QuilspringTown_University_Text_LoungeBoy, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_EventScript_LoungeBoy_Post::
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, QuilspringTown_University_EventScript_LoungeBoy_End
	setspeaker Speaker_WeirdBoy
	msgbox QuilspringTown_University_Text_LoungeBoy_Post, MSGBOX_NPC
	giveitem ITEM_TM_HIDDEN_POWER
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	releaseall
	end

QuilspringTown_University_EventScript_LoungeBoy_End::
	setspeaker Speaker_WeirdBoy
	msgbox QuilspringTown_University_Text_LoungeBoy_End, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_LoungeBoy:
	.string "I know what you're here for.\p"
	.string "You've come for my power, as they\n"
	.string "all do. I knew it.\p"
	.string "You haven't even defeated the\n"
	.string "Quilspring Gym?!\p"
	.string "Hahahahaha you are not worthy of\n"
	.string "my power.$"

QuilspringTown_University_Text_LoungeBoy_Post:
	.string "Well well well, would you look\n"
	.string "at that. My sources say that you\l"
	.string "have defeated the Quilspring Gym.\p"
	.string "You may be strong enough now to\n"
	.string "handle my power, which I have\l"
	.string "hidden from the other students.\p"
	.string "Be careful with it.\p"

QuilspringTown_University_Text_LoungeBoy_End:
	.string "Use my power wisely.$"

QuilspringTown_University_EventScript_James::
	lockall
	goto_if_set FLAG_DEFEATED_QUILSPRING_GYM, QuilspringTown_University_EventScript_James_Post
	setspeaker Speaker_James
	msgbox QuilspringTown_University_Text_James, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_EventScript_James_Post::
	setspeaker Speaker_James
	msgbox QuilspringTown_University_Text_James_Post, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_James:
	.string "I can't believe I lost to you\n"
	.string "again, {PLAYER}!\p"
	.string "You are getting really strong. I\n"
	.string "guess we'll just have to train\l"
	.string "even harder...$"

QuilspringTown_University_Text_James_Post:
	.string "Congratulations on beating Nyx!\n"
	.string "I want to challenge her next!$"

QuilspringTown_University_EventScript_Isabel::
	lockall
	setspeaker Speaker_Isabel
	msgbox QuilspringTown_University_Text_Isabel, MSGBOX_NPC
	releaseall
	end

QuilspringTown_University_Text_Isabel:
	.string "Ah hey {PLAYER}!\p"
	.string "After everything that happened in\n"
	.string "that cave on Route 7, I knew I had\l"
	.string "to keep researching.\p"
	.string "Hopefully I can find more texts that\n"
	.string "help explain and decipher the runes\l"
	.string "we found.$"

QuilspringTown_University_EventScript_Pine::
	lockall
	faceplayer
	goto_if_set FLAG_DEFEATED_QUILSPRING_GYM, QuilspringTown_University_EventScript_PinePostGym
	goto_if_eq VAR_STORY, 10, QuilspringTown_University_EventScript_PineItems
	setspeaker Speaker_Pine
	msgbox QuilspringTown_University_Text_PineDefault, MSGBOX_NPC
	closemessage
	releaseall
	end

QuilspringTown_University_EventScript_PineItems::
	setspeaker Speaker_Pine
	msgbox QuilspringTown_University_Text_PineWelcome, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_PARCEL
	setspeaker Speaker_Pine
	msgbox QuilspringTown_University_Text_PineExplain, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ENABLE_SELECT_MENU
	setflag FLAG_DEXNAV_GET
	setvar VAR_STORY, 11
	closemessage
	releaseall
	end

QuilspringTown_University_EventScript_PinePostGym::
	goto_if_set FLAG_RECEIVED_HM_CUT, LOCALID_QUIL_JAMES
	setspeaker Speaker_Pine
	msgbox QuilspringTown_University_Text_PineCongrats, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_EEVEE, 10
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	setspeaker Speaker_Pine
	msgbox QuilspringTown_University_Text_PineContinue, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNI_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	delay 10
	applymovement LOCALID_QUIL_PINE, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_UNI_JAMES, QuilspringTown_University_Movement_JamesEnter
	waitmovement 0
	setspeaker Speaker_James
	msgbox QuilspringTown_University_Text_JamesErewood, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_CUT_TOOL
	setspeaker Speaker_James
	msgbox QuilspringTown_University_Text_JamesCut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_UNI_JAMES, QuilspringTown_University_Movement_JamesLeave
	waitmovement 0
	setflag FLAG_RECEIVED_HM_CUT
	releaseall
	end

QuilspringTown_University_EventScript_PineDefaultPost::
	setspeaker Speaker_Pine
	msgbox QuilspringTown_University_Text_PineDefault, MSGBOX_NPC
	closemessage
	releaseall
	end

QuilspringTown_University_Text_PineDefault:
	.string "You have been making great strides\n"
	.string "as a Pokémon Trainer.\p"
	.string "Keep up the good work!$"

QuilspringTown_University_Text_PineWelcome:
	.string "There you are {PLAYER}, I've been\n"
	.string "expecting you!\p"
	.string "I must apologize again for not\n"
	.string "giving you the items that I usually\l"
	.string "do to new Trainers!\p"
	.string "Without further ado, please accept\n"
	.string "this Trainer's Kit!$"

QuilspringTown_University_Text_PineExplain:
	.string "There are many items in that kit,\n"
	.string "so please allow me to explain them.\p"
	.string "First is the Dexnav. Use the Dexnav\n"
	.string "to record and search for Pokémon\l"
	.string "you may encounter.\p"
	.string "It is the perfect item to help fill\n"
	.string "out your Pokédex.\p"
	.string "Next are a couple of items to help\n"
	.string "you with your Pokémon:\p"
	.string "the Infinite Repel, the EXP Share,\n"
	.string "and the Camping Tent.\p"
	.string "These items help you repel wild\n"
	.string "Pokémon, allow all Pokémon to\l"
	.string "gain experience,\p"
	.string "and rest until a different time\n"
	.string "of day, respectively.\p"
	.string "If you have any questions, you\n"
	.string "can view the guides that I have\l"
	.string "on the bookshelf in the back.\p"
	.string "Finally, there is a Trainer Phone\n"
	.string "that will allow you to call others\l"
	.string "on your journey.\p"
	.string "There is one other thing that I\n"
	.string "may want your help with,\p"
	.string "but I think I should wait on that\n"
	.string "until you have proven yourself\l"
	.string "more as a Trainer.\p"
	.string "Come back after defeating the Gym\n"
	.string "Leader, Nyx, and we'll talk.\p"
	.string "Good luck to you!$"

QuilspringTown_University_Text_PineCongrats:
	.string "I see you now have the Ink Badge,\n"
	.string "congratulations on your victory!\p"
	.string "While she is the first Gym Leader\n"
	.string "in Serenado, Nyx is certainly no\l"
	.string "pushover as a Trainer.\p"
	.string "Now, I am certain you are the right\n"
	.string "person to help me out.\p"
	.string "In my research I have come across a\n"
	.string "Pokémon that is not normally native\l"
	.string "to Serenado,\p"
	.string "but I believe it has the ability to\n"
	.string "thrive in this environment.\p"
	.string "I believe that studying this Pokémon,\n"
	.string "Eevee, will give us great insights\p"
	.string "into how Pokémon adapt to new\n"
	.string "environments, especially since Eevee\l"
	.string "can evolve into many different Pokémon.\p"
	.string "As a more experienced Trainer I trust\n"
	.string "that you will take good care of this\l"
	.string "Pokémon, and bring it on your journey.\p"
	.string "Please welcome Eevee to your team!$"

QuilspringTown_University_Text_PineContinue:
	.string "Now then!\p"
	.string "If you wish to continue your adventure\n"
	.string "towards the Pokémon League, you should\l"
	.string "make your way through Erewood Grove.\p"
	.string "On the end of Route 6 lies Sundara\n"
	.string "Village, where the next Gym awaits you.$"

QuilspringTown_University_Text_JamesErewood:
	.string "Are you going through Erewood Grove?\p"
	.string "The forest is really dense, it's almost\n"
	.string "impossible to get through! You'll need\l"
	.string "a way of cutting down trees!\p"
	.string "I can help you out there, the good thing\n"
	.string "about my dad being a woodcutter is I\l"
	.string "have a spare axe on me!$"

QuilspringTown_University_Text_JamesCut:
	.string "You can use that to cut down small\n"
	.string "trees. Sometimes your Pokémon may want\l"
	.string "to help you as well!\p"
	.string "I'll meet you in Erewood Grove to show\n"
	.string "you how to use it.$"


QuilspringTown_University_Movement_JamesEnter:
	walk_left
	walk_up
	walk_left
	step_end

QuilspringTown_University_Movement_JamesLeave:
	walk_right
	walk_down
	walk_right
	face_down
	step_end


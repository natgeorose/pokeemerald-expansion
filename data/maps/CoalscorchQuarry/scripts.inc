CoalscorchQuarry_MapScripts::
	.byte 0

Speaker_Michael:
    .string "Michael$"

CoalscorchQuarry_EventScript_Michael::
	trainerbattle_single TRAINER_GRUNT_MICHAEL, CoalscorchQuarry_Text_MichaelIntro, CoalscorchQuarry_Text_MichaelDefeat
	setspeaker Speaker_Michael
	msgbox CoalscorchQuarry_Text_MichaelPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Lilith:
    .string "Lilith$"

CoalscorchQuarry_EventScript_Lilith::
	trainerbattle_single TRAINER_GRUNT_LILITH, CoalscorchQuarry_Text_LilithIntro, CoalscorchQuarry_Text_LilithDefeat
	setspeaker Speaker_Lilith
	msgbox CoalscorchQuarry_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Azriel:
    .string "Azriel$"

CoalscorchQuarry_EventScript_Azriel::
	trainerbattle_single TRAINER_GRUNT_AZRIEL, CoalscorchQuarry_Text_AzrielIntro, CoalscorchQuarry_Text_AzrielDefeat
	setspeaker Speaker_Azriel
	msgbox CoalscorchQuarry_Text_AzrielPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Sarah:
    .string "Sarah$"

CoalscorchQuarry_EventScript_Sarah::
	trainerbattle_single TRAINER_GRUNT_SARAH, CoalscorchQuarry_Text_SarahIntro, CoalscorchQuarry_Text_SarahDefeat
	setspeaker Speaker_Sarah
	msgbox CoalscorchQuarry_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Amy:
    .string "Amy$"

CoalscorchQuarry_EventScript_Amy::
	trainerbattle_single TRAINER_GRUNT_AMY, CoalscorchQuarry_Text_AmyIntro, CoalscorchQuarry_Text_AmyDefeat
	setspeaker Speaker_Amy
	msgbox CoalscorchQuarry_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

CoalscorchQuarry_EventScript_InitiatePickaxe::
	lockall
	goto_if_unset FLAG_RECEIVED_HM_ROCK_SMASH, CoalscorchQuarry_EventScript_MagnusIntro
	releaseall
	end

CoalscorchQuarry_EventScript_MagnusIntro::
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_COALSCORCH_MAGNUS, Common_Movement_ExclamationMark
	waitmovement
	applymovement LOCALID_COALSCORCH_MAGNUS, Common_Movement_WalkDown2
	waitmovement
	setspeaker Speaker_Magnus
	msgbox CoalscorchQuarry_Text_MagnusIntro, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_EVIOLITE
	closemessage
	setspeaker Speaker_Magnus
	msgbox CoalscorchQuarry_Text_MagnusEviolite, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_COALSCORCH_MAGNUS, Common_Movement_ExclamationMark
	waitmovement
	setspeaker Speaker_Magnus
	msgbox CoalscorchQuarry_Text_MagnusYoullNeed, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COALSCORCH_MAGNUS, Common_Movement_WalkUp2
	waitmovement
	delay 10
	applymovement LOCALID_COALSCORCH_MAGNUS, Common_Movement_WalkDown2
	waitmovement
	giveitem ITEM_ROCK_SMASH_TOOL
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	closemessage 
	setspeaker Speaker_Magnus
	msgbox CoalscorchQuarry_Text_MagnusPickaxe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COALSCORCH_MAGNUS, Common_Movement_WalkUp2
	waitmovement
	releaseall
	end

CoalscorchQuarry_Text_MagnusIntro:
	.string "Ah {PLAYER}, I'm glad to see\n"
	.string "that you made it here okay!\p"
	.string "I'm sorry for leaving so\n"
	.string "suddenly, but thankfully it\l"
	.string "looks like the miners are safe.\p"
	.string "Please accept this as a token\n"
	.string "of my thanks.$"

CoalscorchQuarry_Text_MagnusEviolite:
	.string "That item is called an Eviolite,\n"
	.string "it's a powerful held item that\l"
	.string "helps Pokémon who can still evolve.\p"
	.string "I have no doubt that you will be\n"
	.string "able to use it effectively.\p"
	.string "Now it seems like the Chosen have\n"
	.string "stolen some mining equipment, but\l"
	.string "I have no idea for what purpose.\p"
	.string "I believe that in driving them out\n"
	.string "of Coalscorch Quarry we will also\l"
	.string "figure out what their plan is.\p"
	.string "I must stay here and protect the\n"
	.string "miners, so I'm counting on you to\l"
	.string "help defeat the Chosen.$"
	
CoalscorchQuarry_Text_MagnusYoullNeed:
	.string "Oh, but to access the whole quarry\n"
	.string "you'll need the ability to break\l"
	.string "rocks! Let me see...$"

CoalscorchQuarry_Text_MagnusPickaxe:
	.string "That pickaxe will make traversing\n"
	.string "the quarry much easier!\p"
	.string "But be careful, I'm sure the Chosen\n"
	.string "have some sort of leader here.\p"
	.string "It would be wise not to\n"
	.string "underestimate their power.$"





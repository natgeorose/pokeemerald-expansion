Route7_B1F_MapScripts::
	.byte 0

Speaker_Foster:
    .string "Foster$"

Route7_B1F_EventScript_Foster::
	trainerbattle_single TRAINER_FOSTER, Route7_B1F_Text_FosterIntro, Route7_B1F_Text_FosterDefeat
	setspeaker Speaker_Foster
	msgbox Route7_B1F_Text_FosterPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Jesse:
    .string "Jesse$"

Route7_B1F_EventScript_Jesse::
	trainerbattle_single TRAINER_JESSE, Route7_B1F_Text_JesseIntro, Route7_B1F_Text_JesseDefeat
	setspeaker Speaker_Jesse
	msgbox Route7_B1F_Text_JessePostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Felix:
    .string "Felix$"

Route7_B1F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, Route7_B1F_Text_FelixIntro, Route7_B1F_Text_FelixDefeat
	setspeaker Speaker_Felix
	msgbox Route7_B1F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end




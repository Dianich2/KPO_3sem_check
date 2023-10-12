#include"stdafx.h"
#include"Error.h"
namespace Error
{
	//0-99 ñèñòåìíûå îøèáêè
	//100-109 îøèáêè ïàğàìåòğîâ
	//110-119îøèáêè îòêğûòèÿ è ÷òåíèÿ ôàéëîâ
	ERROR errors[ERROR_MAX_ENTRY] = {
		ERROR_ENTRY(0,"Íåäîïóñòèìûé êîä îøèáêè"),
		ERROR_ENTRY(1,"Ñèñòåìíûé ñáîé"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40),
		ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80),ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100,"Ïàğàìåòğ -in äîëæåí áûòü çàäàí"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104,"Ïğåâûøåíà äëèíà âõîäíîãî ïàğàìåòğà"),
		ERROR_ENTRY(105,"Äóáëèğîâàíèå èäåíòèôèêàòîğà"),
		ERROR_ENTRY(106,"Èäåíòèôèêàòîğ íåîïğåäåë¸í"),ERROR_ENTRY_NODEF(107),ERROR_ENTRY_NODEF(108),ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110,"Îøèáêà ïğè îòêğûòèè ôàéëà ñ èñõîäíûì êîäîì (-in)"),
		ERROR_ENTRY(111,"Íåäîïóñòèìûé ñèìâîë â èñõîäíîì ôàéëå (-in)"),
		ERROR_ENTRY(112,"Îøèáêà ïğè ñîçäàíèè ôàéëà ñ ïğîòîêîëîì (-log)"),
		ERROR_ENTRY(113,"Îøèáêà ïğè ñîçäàíèè âûõîäíîãî ôàéëà ñ ğàñøèğåíèåì .out"),
		ERROR_ENTRY(114,"Íåäîïóñòèìûé ğàçìåğ òàáëèöû ëåêñåì"),
		ERROR_ENTRY(115,"Ïğåâûøåí ğàçìåğ òàáëèöû ëåêñåì"),
		ERROR_ENTRY(117,"Íåäîïóñòèìûé ğàçìåğ òàáëèöû èäåíòèôèêàòîğîâ"),
		ERROR_ENTRY(118,"Ïğåâûøåí ğàçìåğ òàáëèöû èäåíòèôèêàòîğîâ"),
		ERROR_ENTRY(119,"Ïğåâûøåíà äëèíà ëåêñåìû"),
		ERROR_ENTRY_NODEF10(120),
		ERROR_ENTRY_NODEF10(130),ERROR_ENTRY_NODEF10(140),ERROR_ENTRY_NODEF10(150),ERROR_ENTRY_NODEF10(160),
		ERROR_ENTRY_NODEF10(170),ERROR_ENTRY_NODEF10(180),ERROR_ENTRY_NODEF10(190),ERROR_ENTRY_NODEF100(200),ERROR_ENTRY_NODEF100(300),
		ERROR_ENTRY_NODEF100(400),ERROR_ENTRY_NODEF100(500),ERROR_ENTRY_NODEF100(600),ERROR_ENTRY_NODEF100(700),ERROR_ENTRY_NODEF100(800),
		ERROR_ENTRY_NODEF100(900)
	};
	ERROR geterror(int id)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
		{
			return errors[id];
		}
		else
		{
			return errors[0];
		}
	}
	ERROR geterrorin(int id, int line = -1, int col = -1)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)	
		{
			errors[id].inext.col = col;
			errors[id].inext.line = line;
			return errors[id];
		}
		else
		{
			return errors[0];
		}
	}
};
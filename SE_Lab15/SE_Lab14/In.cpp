#include"stdafx.h"
#include"In.h"
#include"Error.h"
#include"Out.h"
#include"Parm.h"
#include"Log.h"
#include <cstring>
#include <cstdlib>

namespace In
{
	IN getin(Parm::PARM parm)
	{
		IN in_result;
		int position = 0;
		unsigned char symbol;
		in_result.size = 0;
		in_result.lines = 1;
		std::ifstream file;
		file.open(parm.in);
		if (!file.is_open())
		{
			throw ERROR_THROW(110);
		}
		in_result.text = new unsigned char[IN_MAX_LEN_TEXT];
		 char* tmp = new char[IN_MAX_LEN_TEXT];
		 Log::LOG log = Log::INITLOG;
		 Out::OUT out = Out::INITOUT;
		 out = Out::GetOut(parm.out);
		 log = Log::getlog(parm.log);
		 Log::WriteLog(log);
		 Log::WriteParm(log,parm);
		 while (file.getline(tmp, 1000))
		 {
			 if (in_result.lines > 1)
			 {
				 in_result.text[in_result.size] = '|';
				 in_result.size++;
			 }
			 for(int i=0;i<strlen(tmp);i++)
			 {
				 symbol = tmp[i];
				 position++;
				 switch (in_result.code[int((unsigned char)symbol)])
				 {
				 case IN::T:
					 in_result.text[in_result.size] = (unsigned)symbol;
					 in_result.size++;
					 break;
				 case IN::F:
					 in_result.text[in_result.size] = '\0';
					 Out::WriteText(out, in_result);
					 Out::WriteError(out, ERROR_THROW_IN(111, in_result.lines, position));
					 Log::WriteError(log, ERROR_THROW_IN(111, in_result.lines, position));
					 Log::Close(log);
					 Out::Close(out);
					 throw ERROR_THROW_IN(111, in_result.lines, position);
					 break;
				 case IN::I:
					 in_result.ignore++;
					 position++;
					 break;
				 default:
					 in_result.text[in_result.size] = in_result.code[symbol];
					 in_result.size++;
					 position++;
				 }
			 }
			 in_result.lines++;
			 position = 0;
		 }
		in_result.text[in_result.size] = '\0';
		Out::WriteText(out, in_result);
		Log::WriteIn(log, in_result);
		Log::Close(log);
		Out::Close(out);
		return in_result;
	}
}
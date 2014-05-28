/**
* Copyright (C) 2014, BMW Car IT GmbH
* Author: Jonas Sticha (Jonas.Sticha@bmw-carit.de)
*
* This software is licensed under BSD 3-clause License
* (see http://spdx.org/licenses/BSD-3-Clause).
**/

#include "Config.h"
#include "ArgumentParser.h"

ArgumentParser::ArgumentParser()
{
}

bool ArgumentParser::parseArgs(int argc, char* argv[])
{
	Config* config = Config::getConfig();
	config->loops = 1000;
	config->frequency = 1000;
	config->testnodeRT = false;
	bool error = false;
	for(int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		if(arg.compare("--rtSched") == 0)
		{
			std::string val(argv[i+1]);
			if(val.compare("0") == 0)
			{
				config->testnodeRT = false;
			} else if(val.compare("RR") == 0)
			{
				config->testnodeRT = true;
				config->fifoScheduling = false;
			} else if(val.compare("FIFO") == 0)
			{
				config->testnodeRT = true;
				config->fifoScheduling = true;
			} else {
				error = true;
				continue;
			}
			i++;
		} else if(arg.compare("--rpts") == 0)
		{
			config->loops = atoi(argv[i+1]);
			i++;
		} else if(arg.compare("--fq") == 0)
		{
			config->frequency = atoi(argv[i+1]);
			i++;
		} else if(arg.compare("--fp") == 0)
		{
			config->namePrefix = std::string(argv[i+1]);
			i++;
		}
	}
	return !error;
}

std::string ArgumentParser::getUsage()
{
	return "Args: [--fq <frequency(Hz)>] [--rpts <repetitions>] [--rtSched <0/RR/FIFO>] [--fp <file_prefix>]";
}

ArgumentParser::~ArgumentParser()
{
}
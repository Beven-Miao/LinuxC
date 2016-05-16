//============================================================================
// Name        : PowerSupply.cpp
// Author      : Beven
// Version     :
// Copyright   : Your copyright notice
// Description : Control the current and state of the PowerSupply. Exercise about class hierarchies and operator overloading.
//============================================================================

#include "PowerSupply.hpp"

#include <sys/unistd.h>
#include <iostream>
#include <iterator>
#include <utility>

bool RampedPowerSupply::loadRamp(const std::vector<double> & values)
{
	return ((isOn() && !_ramping) ? _rampedValue = values, true : false);
}

bool RampedPowerSupply::startRamp(const uint32_t msec)
{
	//The power supply must be on when set the current values
	if ((!isOn() || (msec <= 0) || (_ramping)))
	{
		return false;
	}
	else
	{
		std::vector<double>::iterator begin = _rampedValue.begin();
		std::vector<double>::iterator end = _rampedValue.end();

		//set the currents
		while (begin != end)
		{
			double rampCurrent = *begin++;

			std::cout << "setting current to" << rampCurrent << std::endl;

			if (!RampedPowerSupply::set(rampCurrent))
			{
				return (_ramping = false);
			}
			sleep(msec / 1000);
		}
	}
	_ramping = false;

	return true;
}

PowerSupplyNarrow::PowerSupplyNarrow(std::shared_ptr<PowerSupplyBasic> powerSupply)
{
	_powerSupply = powerSupply;
	_fail = true;

	if (_powerSupply != 0)
	{
		_fail = _powerSupply->off(), _powerSupply->on();
		_powerSupply->off();
	}
}

bool PowerSupplyNarrow::execute(const std::string &command,
		const std::vector<double> &parameters, double &currentValue)
{
	if (!_powerSupply || _fail)
	{
		return false;
	}

	//Parse the command
	if (command == "on")
	{
		return _powerSupply->on();
	}
	else if (command == "off")
	{
		return _powerSupply->off();
	}
	else if (command == "reset")
	{
		return _powerSupply->reset();
	}
	else if (command == "current_get")
	{
		return _powerSupply->get(currentValue);
	}
	else if (command == "current_set")
	{

		for (std::vector<double>::const_iterator iter = parameters.begin();
				iter != parameters.end(); iter++)
		{
			bool isSuccess = _powerSupply->set(*iter);
			if (!isSuccess)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool Circuit::execute(const std::string &deviceName, const std::string &command,
		const std::vector<double> &parameters, double &currentValue)
{
	std::map<std::string, std::shared_ptr<PowerSupplyNarrow>>::iterator iter =
			_powerSupplies.find(deviceName);

	if (iter != _powerSupplies.end())
	{
		return iter->second->execute(command, parameters, currentValue);
	}
	else
	{
		return false;
	}
}

void Circuit::add(std::shared_ptr<PowerSupplyNarrow>powerSupplyWrapper,
		const std::string &deviceName)
{
	if (powerSupplyWrapper != 0)
	{
		_powerSupplies[deviceName] = powerSupplyWrapper;
	}
}


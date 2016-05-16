/*
 * PowerSupply.h
 *
 *  Created on: 2016Äê5ÔÂ9ÈÕ
 *      Author: Beven
 */

#ifndef POWERSUPPLY_HPP_
#define POWERSUPPLY_HPP_

#include <sys/_stdint.h>
#include <map>
#include <memory>
#include <string>
#include <vector>

/**
 * PowerSupply abstract class.
 *
 */
class PowerSupplyBasic
{
public:

	/**
	 * State of the power supply
	 */
	enum State
	{
		OFF = 0, ON = 1
	};

	/**
	 * constructor
	 */
	PowerSupplyBasic() :
			_state(OFF), _current(0.0)
	{
	}

	/**
	 * Switch on the power supply
	 * @return true power supply is on,
	 *         false set power supply to on fail
	 */
	virtual bool on() = 0;

	/**
	 * Switch off the power supply
	 * @return true power supply is off,
	 * 		   false set off power supply fail
	 */
	virtual bool off() = 0;

	/**
	 * Reset the power supply
	 * @return true reset successful,
	 * 			false reset fail
	 */
	virtual bool reset() = 0;

	/**
	 * Get the value of current
	 * @param current value of the current
	 * @return true get the current successful,
	 * 			false get the current fail
	 */
	virtual bool get(double &current) = 0;

	/**
	 * Set the value of the power supply
	 * @param value the value set to current
	 * @return true set the current successful,
	 * 			false set the current fail
	 */
	virtual bool set(const double value) = 0;

	/**
	 * Destructor
	 */
	virtual ~PowerSupplyBasic()
	{
	}

protected:
	State _state;
	double _current;
};

/**
 * PowerSupplyBasic imlementation.
 */
class PowerSupply: public PowerSupplyBasic
{
public:

	/**
	 * Switch on the power supply
	 * @return true power supply is on,
	 *         false set power supply to on fail
	 */
	bool on()
	{
		return (!isOn() ? _state = ON, reset(), true : false);
	}

	/**
	 * Switch off the power supply
	 * @return true power supply is off,
	 * 		   false set off power supply fail
	 */
	bool off()
	{
		return (isOn() ? _state = OFF, true : false);
	}

	/**
	 * Reset the power supply
	 * @return true reset successful,
	 * 			false reset fail
	 */
	bool reset()
	{
		return (isOn() ? _current = 0.0, true : false);
	}

	/**
	 * Get the value of current
	 * @param current value of the current
	 * @return true get the current successful,
	 * 			false get the current fail
	 */
	bool get(double &current)
	{
		return (isOn() ? current = _current, true : false);
	}

	/**
	 * Set the value of the power supply. Set the state off when the current is 0.
	 * @param value the value set to current
	 * @return true set the current successful,
	 * 			false set the current fail
	 */
	bool set(const double value)
	{
		return ((isOn() && (value >= 0)) ?
				(value == 0.0 ? off() : _current = value), true : false);
	}

	/**
	 * Return the state of the power supply.
	 * @return true power supply is on,
	 * 			false power supply is off
	 */
	bool isOn()
	{
		return (_state == ON);
	}

	/**
	 * Destructor
	 */
	~PowerSupply() = default;
};

/**
 * Power supply support Ramp functions
 */
class RampedPowerSupply: public PowerSupply
{
public:

	/**
	 * Construction
	 */
	RampedPowerSupply() :
			_ramping(false)
	{
	}

	/**
	 * Load ramp for power supply from values
	 * @param values
	 * @return	true load successful,
	 * 			false load fail
	 */
	bool loadRamp(const std::vector<double> & values);

	/**
	 * Start set values ftom the ramp
	 * @param msec
	 * @return	true set values successful,
	 * 			false set values fail
	 */
	bool startRamp(const uint32_t msec);

	/**
	 * Destructor
	 */
	~RampedPowerSupply() = default;

private:
	std::vector<double> _rampedValue;
	bool _ramping;
};

/**
 * Narrow the power supply in the Wrapper
 */
class PowerSupplyNarrow
{
public:
	PowerSupplyNarrow(std::shared_ptr<PowerSupplyBasic> powerSupply);

	/**
	 * Excute a command on the wrapped power supply
	 * @param command command to be excuted
	 * @param parameters values of the current
	 * @param currentValue current value of current
	 * @return	true excuted the command successful,
	 * 			fale excuted the command fail
	 */
	bool execute(const std::string &command,
			const std::vector<double> &parameters, double &currentValue);

	~PowerSupplyNarrow() = default;
private:
	std::shared_ptr<PowerSupplyBasic> _powerSupply;
	bool _fail;
};

/**
 * Circuit receive commands and send it to the wrapper
 */
class Circuit
{
public:

	/**
	 * Constructor
	 */
	Circuit() = default;

	/**
	 *Add a new device to the circuit
	 * @param powerSupplyWrapper pointer of power supply
	 * @param name name of the power supply
	 */
	void add(std::shared_ptr<PowerSupplyNarrow> powerSupplyWrapper, const std::string &name);

	/**
	 *Excuted the command on the named device
	 * @param deviceName name of the device/power supply
	 * @param command command to be excuted
	 * @param parameters	values of the current
	 * @param currentValue	present value of the current
	 * @return	true excute the command successful,
	 * 			false excute the command fail
	 */
	bool execute(const std::string &deviceName, const std::string &command,
			const std::vector<double> &parameters, double &currentValue);

	/**
	 * Destructor
	 */
	~Circuit() = default;

private:

	std::map<std::string, std::shared_ptr<PowerSupplyNarrow>> _powerSupplies;
};

#endif /* POWERSUPPLY_HPP_ */

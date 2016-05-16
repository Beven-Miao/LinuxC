/*
 * PowerSupply_test.cpp
 *
 *  Created on: 2016Äê5ÔÂ9ÈÕ
 *      Author: Beven
 */

#include "../PowerSupply.hpp"

#include <gtest/gtest.h>
#include <gtest/gtest-message.h>

TEST(PowerSupplyTest, basicFunctionTest)
{
	PowerSupply rps;

	double current;

	EXPECT_EQ(true, rps.on());
	EXPECT_EQ(true, rps.off());

	EXPECT_EQ(false, rps.off());
	EXPECT_EQ(false, rps.reset());
	EXPECT_EQ(false, rps.set(2.0));
	EXPECT_EQ(false, rps.get(current));

	EXPECT_EQ(true, rps.on());
	EXPECT_EQ(true, rps.set(2.0));
	EXPECT_EQ(true, rps.get(current));
	EXPECT_EQ(2.0, current);

	EXPECT_EQ(true, rps.reset());
	EXPECT_EQ(true, rps.get(current));
	EXPECT_EQ(0.0, current);
}

TEST(RampedPowerSupplyTest, BasicRampedFunctionTest)
{
	RampedPowerSupply rps;

	double current;

	EXPECT_EQ(true, rps.on());
	EXPECT_EQ(true, rps.off());

	EXPECT_EQ(false, rps.off());
	EXPECT_EQ(false, rps.reset());
	EXPECT_EQ(false, rps.set(2.0));
	EXPECT_EQ(false, rps.get(current));

	EXPECT_EQ(true, rps.on());
	EXPECT_EQ(true, rps.set(2.0));
	EXPECT_EQ(true, rps.get(current));
	EXPECT_EQ(2.0, current);

	EXPECT_EQ(true, rps.reset());
	EXPECT_EQ(true, rps.get(current));
	EXPECT_EQ(0.0, current);
}

TEST(RampedPowerSupplyTest, RampedFunctionTest)
{
	RampedPowerSupply rps;
	double current;
	std::vector<double> values;
	for (double i = 1.0; i <= 8.0;)
	{
		values.push_back(i);
		i += 1.0;
	}

	EXPECT_EQ(true, rps.on());
	EXPECT_EQ(false, rps.startRamp(0));

	EXPECT_EQ(true, rps.off());
	EXPECT_EQ(false, rps.loadRamp(values));
	EXPECT_EQ(false, rps.startRamp(600));

	EXPECT_EQ(true, rps.on());
	EXPECT_EQ(true, rps.loadRamp(values));
	EXPECT_EQ(true, rps.startRamp(600));

	EXPECT_EQ(true, rps.get(current));
	EXPECT_EQ(8.0, current);
}

TEST(PowerSupplyNarrwTest,TestCommandBasic)
{
	std::vector<double> cmdArgs =
	{ 1.0, 2.0, 3.0 };
	std::vector<double> emptyArgs;
	double current = 0.0;
	std::shared_ptr<PowerSupply> ps = std::make_shared<PowerSupply>();
	std::shared_ptr<PowerSupplyNarrow> psn =
			std::make_shared<PowerSupplyNarrow>(ps);

	EXPECT_EQ(true, ps->on());

	EXPECT_EQ(true, psn->execute("reset", emptyArgs, current))
			<< "narrow_reset";
	EXPECT_EQ(true, psn->execute("current_set", cmdArgs,
					current)) << "currentSet";
	EXPECT_EQ(true, psn->execute("current_get", emptyArgs, current))
			<< "currentGet";
	EXPECT_EQ(3.0, current) << "current value does not match failed";
	EXPECT_EQ(true, psn->execute("off", emptyArgs, current))
			<< "circDevice_off";

}

TEST(CircuitTest, TestCommandBasics)
{
	std::vector<double> cmdArgs =
	{ 0.5 };
	std::vector<double> emptyArgs;
	double current = 0.0;
//	Circuit circuit;
	std::unique_ptr<Circuit> circuit(new Circuit());

	std::shared_ptr<PowerSupply> ps = std::make_shared<PowerSupply>();

	std::shared_ptr<PowerSupplyNarrow> nsp = std::make_shared<PowerSupplyNarrow>(ps);

// a narrow power supply only wraps the power supply which has its
// own life-cycle but the ownership of the narrow power supplies is
// in the hands of the circuit
	circuit->add(nsp, "ps1");
	/* It is still possible to use the power supply device.
	 * Just an illustration where to get the power supply device,
	 * but here it is not intended to be used this way. */
	EXPECT_EQ(true, ps->on()) << "device_on";
	/* The wrapped device is already turned on.
	 * Just an illustration of the wrapper interface,
	 * but here it is not intended to be used this way. */
	EXPECT_EQ(true, circuit->execute("ps1", "reset", emptyArgs, current))
			<< "narrow_reset";
	/* Set the current over the control request. */
	EXPECT_EQ(true, circuit->execute("ps1", "current_set", cmdArgs,
					current)) << "currentSet";
	/* Returned current value must match the previously set one. */
	EXPECT_EQ(true, circuit->execute("ps1", "current_get", emptyArgs,
					current)) << "currentGet";
	EXPECT_EQ(0.5, current) << "current value does not match failed";
	/* We conclude our interface presentation with turning the device
	 off. */
	EXPECT_EQ(true, circuit->execute("ps1", "off", emptyArgs, current))
			<< "circDevice_off";
}

TEST(CircuitTest, ExecuteCommands)
{

	std::vector<double> cmdArgs =
	{ 1.0, 2.0, 5.0 };
	std::vector<double> currentNegArgs =
	{ -5.0 };
	std::unique_ptr<Circuit> circuit(new Circuit());
	double current = 10.0;

//	RampedPowerSupply rampedPowerSupply;
//	PowerSupplyNarrow *rampedPowerSupplyNarrow = new PowerSupplyNarrow(
//			&rampedPowerSupply);
	std::shared_ptr<RampedPowerSupply> rampedPowerSupply = std::make_shared<
			RampedPowerSupply>();
	std::shared_ptr<PowerSupplyNarrow> rampedPowerSupplyNarrow =
			std::make_shared<PowerSupplyNarrow>(rampedPowerSupply);

	std::shared_ptr<PowerSupply> powerSupply = std::make_shared<PowerSupply>();
	std::shared_ptr<PowerSupplyNarrow> powerSupplyNarrow = std::make_shared<
			PowerSupplyNarrow>(powerSupply);

//	PowerSupply powerSupply;
//	PowerSupplyNarrow *powerSupplyNarrow = new PowerSupplyNarrow(&powerSupply);

	circuit->add(rampedPowerSupplyNarrow, "ps1");
	circuit->add(powerSupplyNarrow, "ps2");

	EXPECT_EQ(true, circuit->execute("ps1", "on", cmdArgs, current))
			<< "Ramped Power supply on in OFF state failed";
	EXPECT_EQ(true, circuit->execute("ps1", "off", cmdArgs, current))
			<< "Ramped Power supply off in ON state failed";
	EXPECT_EQ(false, circuit->execute("ps1", "off", cmdArgs, current))
			<< "Ramped Power supply off in OFF state failed";
	EXPECT_EQ(false, circuit->execute("ps1", "current_set", cmdArgs, current))
			<< "Ramped Power supply set in OFF state failed";
	EXPECT_EQ(false, circuit->execute("ps1", "current_get", cmdArgs, current))
			<< "Ramped Power supply get in OFF state failed";
	EXPECT_EQ(false, circuit->execute("ps1", "reset", cmdArgs, current))
			<< "Ramped Power supply reset in OFF state failed";
	EXPECT_EQ(true, circuit->execute("ps1", "on", cmdArgs, current))
			<< "Ramped Power supply on in OFF state failed";
	EXPECT_EQ(true, circuit->execute("ps1", "current_set", cmdArgs, current))
			<< "Ramped Power supply set in ON state failed";
	EXPECT_EQ(false, circuit->execute("ps1", "current_set", currentNegArgs, current))
			<< "Ramped Power supply set negative in ON state failed";
	EXPECT_EQ(true, circuit->execute("ps1", "current_get", cmdArgs, current))
			<< "Ramped Power supply get in ON state failed";
	EXPECT_EQ(5.0, current) << "current value does not match failed";
	EXPECT_EQ(true, circuit->execute("ps1", "reset", cmdArgs,current))
			<< "Ramped Power supply reset in ON state failed";
	EXPECT_EQ(true, circuit->execute("ps1", "current_get", cmdArgs, current))
			<< "Ramped Power supply get in ON state failed";
	EXPECT_EQ(0.0, current) << "current value does not match failed1";

	EXPECT_EQ(true, circuit->execute("ps2", "on", cmdArgs, current))
			<< "Power supply on in OFF state failed";
}


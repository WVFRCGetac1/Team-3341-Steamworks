#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>
#include "OI.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Winch.h"
#include "Subsystems/Acquirer.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	// Create a single static instance of all of your subsystems
	//static std::unique_ptr<ExampleSubsystem> exampleSubsystem;
	static DriveTrain* drive;
	static Shooter* shooter;
	static Winch* winch;
	static Acquirer* acquirer;
	static std::unique_ptr<OI> oi;

	/* Instantiate static data.
	 * Not all classes in WPILib can be instantiated as global / static global data.
	 * Some may need to be instantiated after HAL_Initialize(), which is called in
	 * main().  global and static global data are initialized / instantiated prior to main().
	 * This should be called from Robot::RobotInit();
	 */
	static void initialize();

};

#endif  // COMMAND_BASE_H

# Manual-DoorLock-System
## Descreption
Design a manual door lock system that indicates the door's status using LEDs and a 7-segment 
display. The system uses a DC motor to lock and unlock the door.

![Screenshot 2024-07-11 205737](https://github.com/ahmedfathy21/Manual-DoorLock-System/assets/150164291/e332261f-f328-47b2-99cc-dbc6e5e22386)

###   Components

1. Microcontroller (PIC)

2. LEDs (Red and Green)

3. 7-Segment Display (One)

4. DC Motor

5. Motor Driver (e.g., L298N)

6. Limit Switches (for detecting door position)

7. Push Button (for manual control)

#### Functionality

1. LED Indicators:

   o Red LED: Door is locked.

   o Green LED: Door is unlocked.

2. 7-Segment Display:

   o Displays "L" when the door is locked.

   o Displays "U" when the door is unlocked.

3. DC Motor Control:

   o The motor will lock the door when a lock signal is received.

   o The motor will unlock the door when an unlock signal is received.

4. Limit Switches:

   o Detect if the door is fully locked or fully unlocked.

   o Ensure the motor stops at the correct position.

5. Control:

   o A push button can be used to manually lock or unlock the door.

# Week7 - EEZStudio
## PART 1: Making a new project

Download and install, and run EEZStudio:

https://www.envox.eu/studio/studio-introduction/

https://github.com/eez-open/studio/releases

![eezstudio](pics/eezstudio.png)

File – New Project. Select LVGL, select version 9.X . Type in a project name and select a directory to store your LVGL projects on. Click create project.

![lvgl](pics/lvgl.png)

Click on the blue cog wheel for settings.

![settings](pics/settings.png)

Change Display width to 320 and height to 240. Click the main tab beside the blue settings tab.

![changeSize](pics/changeDisplaySize.png)

In your STM32 project make a “ui” folder under the Core/Src folder

![uiFolder](pics/uiFolder.png)

Right click on your main project name and select properties. Add the Core/Src/ui workspace path.

![workspacePath](pics/workspacePath.png)

Under settings in EEZStudio, select Build. On the right there is an option to select the destination folder. Use the search folders (...) to locate the ui directory that was just made in the STM32CubeIDE. This allows you to send the compiled code to a project directory. 

![destinationFolder](pics/destinationFolder.png)

In main change the width and height to 320 and 240.

![mainChangeSize](pics/mainChangeSize.png)

On the right side expand the background listing and select the drop down and select a color from the color picker.

![colorPicker](pics/colorPicker.png)

Scroll the right hand side down until you see a number of check boxes.
Unselect scrollable.
On the left side there is a HelloWorld label under Widget Structure.
Right click and delete it.

![helloWorldr](pics/helloWorld.png)

From the components palette on the right, drag a label to the screen. Enter your text as “ECET 260” and change its color.

![ECET260](pics/ECET260.png)

Drag a button and a LED onto the screen layout. Name the Button button and the LED led.

![buttonLED](pics/buttonLED.png)

![buttonLED1](pics/buttonLED1.png)

Include ui.h, vars.h, and actions.h to access EEZstudio files

![includes](pics/includes.png)

Initialize it with ui_init

![ui_init](pics/ui_init.png)

Put the ui_tick function just after the Touch_GETXYtouch function.

![ui_tick](pics/ui_tick.png)

Click on the button (not the label on on the button). 
On the left side under ‘User Actions’ click + .
Add a new action called redLedEvent and have the event be PRESSED.
Add a new action called redLedEvent and have the event be RELEASED.

![redLedEvent](pics/redLedEvent.png)

In main.c in UserCode0:

![main](pics/main.png)

In your while(1) loop in main, add  the polling for your blue button, B1 and change the intensity of the software LED.

![while](pics/while.png)

## PART 2: Hardware Configuration

Configure the LED and the KEY pins.

![pinout](pics/pinout.png)
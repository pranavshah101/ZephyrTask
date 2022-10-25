# ZephyrTask
A simple sample that can be used with native_posix and prints two threads.

Please pull the repository and the folder will be renamed as "ZephyrTask".

Store the folder in ZephyrProject/Zephyr/Samples/ZephyrTask.
Building and Running

This application can be built and executed on QEMU as follows:

.. zephyr-app-commands::
   :zephyr-app: samples/ZephyrTask
   :host-os: unix
   :board: native_posix
   :goals: run
   :compact:


Use the following command to run the program:

1.west build -b native_posix samples/ZephyrTask -> This will compile the program and if you are running the program for the first time , make sure you delete the build folder if it exists inside the ZephyrProject->Zephyr. 2. Then run west build -t run , which will run the program.

Pull this Repository and add it in zephyrproject/zephyr/samples.

Once you the folder ready you can go to the terminal and run this command:

If you are directly opening the terminal in zephyrproject/zephyr, you have to use only two command:

1. west build -b native_posix samples/ZephyrTask
2. west build -t run.

If you are opening the terminal and current directory is not zephyrproject/zephyr, please make sure you go the zephyrproject/zephyr directory and run the above given two commands.

If you want to exit the QEMU, you have to Press Ctrl+C . The exceution will stop.

The two threads involved here are "Hello_World" and "My name is Pranav Shah"
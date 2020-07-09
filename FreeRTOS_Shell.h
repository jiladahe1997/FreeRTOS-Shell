#ifndef __FREERTOS_SHELL_H
#define __FREERTOS_SHELL_H

/* FreeRTOS-Shell macro */
#define FREERTOS_SHELL_RECV_QUEUE_LENGTH 32
#define FREERTOS_SHELL_INPUT_BUFFER_LENGTH 64
#define FREERTOS_SHELL_USER_INFO "[root@FreeRTOS]# "
#define FREERTOS_SHELL_EACH_TASKINFO_MAX_SIZE 40   //40 bytes per task is described here: https://www.freertos.org/a00021.html#vTaskList

/* FreeRTOS-CLI macro */
#define FREERTOS_CLI_OUTPUT_MAX_BUFFER_SIZE 128

#include <stdint.h>

void FreeRTOS_Shell(void);
void FreeRTOS_ShellIRQHandle(uint8_t recvData);

#define FREERTOS_SHELL_CMD_REGISTER(pcCommand, pcHelpString, pxCommandInterpreter, cExpectedNumberOfParameters) \
    CLI_Command_Definition_t FreeRTOS_Shell_CMD_definetion_##pxCommandInterpreter __attribute__((section ("FREERTOS_SHELL_CMD_SECTION"))) __attribute__((used)) = { \
        pcCommand,\
        pcCommand":"pcHelpString"\r\n",\
        pxCommandInterpreter,\
        cExpectedNumberOfParameters\
    };

#define FREERTOS_SHELL_START_LOGO \
"\r\n"\
"___________                    _____________________________    _________         \r\n"\
"\\_   _____/______   ____   ____\\______   \\__    ___/\\_____  \\  /   _____/    \r\n"\
" |    __) \\_  __ \\_/ __ \\_/ __ \\|       _/ |    |    /   |   \\ \\_____  \\   \r\n"\
" |     \\   |  | \\/\\  ___/\\  ___/|    |   \\ |    |   /    |    \\/        \\  \r\n"\
" \\___  /   |__|    \\___  >\\___  >____|_  / |____|   \\_______  /_______  /     \r\n"\
"     \\/                \\/     \\/       \\/                   \\/        \\/    \r\n"\
"           _________.__           .__  .__                 \r\n"\
"          /   _____/|  |__   ____ |  | |  |                \r\n"\
"  ______  \\_____  \\ |  |  \\_/ __ \\|  | |  |            \r\n"\
" /_____/  /        \\|   Y  \\  ___/|  |_|  |__            \r\n"\
"         /_______  /|___|  /\\___  >____/____/             \r\n"\
"                 \\/      \\/     \\/                      \r\n"\
"\r\n"
#endif /* __FREERTOS_SHELL_H */